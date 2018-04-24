#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 存放处理后的字符串
char temp_str[255] = { };
// 空格标志
bool temp = false;
// 临时数组
char word[255] = { };
// 关键字
string keyword[] = {
    "main","if","then","while","do","static","defualt","do","int","double",
    "struct","break","else","long","swtich","case","typedf","char","return",
    "const","float","short","continue","for","void","sizeof"
};

int keyword_num[] = {
    1,2,3,4,5,6,39,40,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24
};

// 部分运算符，定界符等
char symbol[9] = { '+','-','*','/','=',';','(',')','#' };

// 对应的种码值
int symbol_num[9] = { 27,28,29,30,38,41,42,43,0 };

bool IsDigit(char ch) {
    if (ch >= '0' && ch <= '9') return true;
    return false;
}

bool IsLetter(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return true;
    return false;
}

int IsSymbol(char ch) {
    for (int i = 0; i < 9; ++i) {
        if (ch == symbol[i]) return i;
    }
    return -1;
}

int IsKeyWord(string str) {
    for (int i = 0; i < 26; ++i) {
        if (str == keyword[i]) return i;
    }
    return 25;
}

void HandleSpace(char *text) {
    int j = 0;
    memset(word, 0, 256);
    temp = false;

    for (size_t i = 0; i < strlen(text); ++i) {
        if (text[i] != ' ' && text[i] != '\t') {
            word[j++] = text[i];
            temp = false;
        }
        else {
            if (!temp && text[i] != '\t') {
                word[j++] = text[i];
                temp = true;
            }
        }
    }
}

void prePro() {
    int j = 0;
    memset(temp_str, 0, 255);
    for (size_t i = 0; i < strlen(word); ++i) {
        if (word[i] == '/' && word[i + 1] == '/') {
            while (i < strlen(word)) ++i;
        }
        else {
            temp_str[j++] = word[i];
        }
    }
}

int main() {

    char instr[255] = {};          // 接收输入字符串
    bool flag = false;             // 多行注释标志,false为未处于注释区域
    string Token;                  // 存放字符串
    char *str = NULL;              // 存放每行的字符串
    char delims[] = " ";           // 分割标志

    freopen("test.cpp","r",stdin);
    freopen("out.txt","w",stdout); // 此行注释后，控制台输出，

    // 否则文本输出
    while((gets(instr)) != NULL)
    {
        HandleSpace(instr);
        prePro();

        str=strtok(temp_str,delims); // 分割字符串

        while(str!=NULL)
        {
            // 头文件，宏定义
            if(*(str)=='#')
            {
                printf("#\n");
                break;
            }

            for(size_t i=0; i<strlen(str);i++)
            {
                if(*(str+i)=='/')
                {
                    if(*(str+i+1)=='*')
                    {
                        flag=true;
                        break;
                    }
                }
                // 注释处理: */,注释区域结束
                if(*(str+i)=='*'&&flag)
                {
                    if(*(str+i+1)=='/')
                    {
                        flag=false;
                        i++;
                        break;
                    }
                }
                // 标识符，关键词
                if(IsLetter(*(str+i))&&(!flag))
                {
                    // printf("进入标识符判断\n");
                    while(IsLetter(*(str+i))||IsDigit(*(str+i)) ||*(str+i)=='_')
                    {
                        Token+=*(str+i);
                        i++;
                    }

                    if(IsKeyWord(Token)!=25)
                    {
                        printf("(%d,  \"%s\")\n",1, Token.c_str());
                    }
                    else printf("(2, \"%s\")\n",Token.c_str());

                    Token="";
                    // printf("退出标识符判断\n");
                }
                if(IsDigit(*(str+i))&&(!flag))
                {
                    // printf("进入数字判断\n");
                    while(IsDigit(*(str+i)))
                    {
                        Token+=*(str+i);
                        i++;
                    }
                    printf("(3, \"%s\")\n",Token.c_str());
                    Token="";
                }

                if (*(str + i) == '+' || *(str + i) == '-' ||
                        *(str + i) == '*' || *(str + i) == '/')
                {
                    printf("(4, \"%c\")\n", *(str + i));
                }
                // <,<=,<>
                else if(*(str+i)=='<'&&(!flag))
                {
                    printf("(4, \"%c\")\n", *(str + i));
                }
                // >,>=
                else if(*(str+i)=='>'&&(!flag))
                {
                    printf("(4, \"%c\")\n", *(str + i));
                }
                // :,:=
                else if(*(str+i)=='='&&(!flag))
                {
                    printf("(4, \"%c\")\n", *(str + i));
                }
                // 余下定界符等
                else if(IsSymbol(*(str+i))!=-1&&(!flag))
                {
                    printf("(%d, \"%c\")\n",5,*(str+i));
                }
            }

            str=strtok(NULL,delims);
        }
    }
}

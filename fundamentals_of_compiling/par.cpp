#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

const int VSIZE = 300;

class Principle {
public:
    string left;
    string right;
    Principle(const char*, const char*);
};

//只考虑不包含varepsilon的情况，且所有元素均只包含一个字母
vector<char> VN;                 //非终结符集
vector<char> VT;                 //终结符集
vector<Principle> principle;     //产生式的集合
int type[VSIZE];                 //每个字符的类型

void init();              //清理工作
int  get_type(char);      //1代表是非终结符，2代表是终结符
bool set_type(char,int);  //设置一个字符的类型
int  get_result();        //获得输入的文法的类型

int main() {

    char buf[1000];
    while(true) {
        puts("Plase input VN:");
        gets(buf);
        for (size_t i = 0; i < strlen(buf); i++) {
            char ch = buf[i];
            if (!isupper(ch)) continue;
            if (get_type(ch)) continue;
            VN.push_back(ch);
            set_type(ch,1);
        }

        puts("Plase input VT:");
        gets(buf);
        for (size_t i = 0 ; i < strlen(buf); i++) {
            char ch = buf[i];
            if (!islower(ch)) continue;
            if (get_type(ch)) continue;
            VT.push_back ( ch );
            set_type(ch,2);
        }
        puts("Plase input produce formula : (format [A::=...a...]), intput \"eixt\" to finish\n");
        while (true) {
            gets(buf);
            if (!strcmp(buf, "exit")) break;

            size_t i;
            for (i = 0 ; i < strlen(buf); i++) {
                if (buf[i] == ':') {
                    buf[i] = 0;
                    i = i + 3;
                    break;
                }
            }
            principle.push_back(Principle(buf, buf + i));
            printf("%s|%s|\n", buf, buf + i);
        }

        int flag = get_result();
        switch (flag) {
            case -1:
                puts("产生式中出现未知字符");
                break;
            case 0:
                puts("0 type");
                break;
            case 1:
                puts("1 type");
                break;
            case 2:
                puts("2 type");
                break;
            case 3:
                puts("3 type");
                break;
            case 4:
                puts("3 type");
                break;
        }
    }
    return 0;
}

Principle::Principle (const char *l, const char *r) {
    left = l;
    right = r;
}

// 判断字符串是否包含未知字符
bool hasError(const string& s) {
    for ( size_t i = 0 ; i < s.length() ; i++ )
        if ( !get_type(s[i]) ) return true;
    return false;
}

// 判断是否为0型文法
bool isZero() {
    for (size_t i = 0; i < principle.size(); i++) {
        if      (hasError(principle[i].left))  return false;
        else if (hasError(principle[i].right)) return false;
    }
    return true;
}

// 判断一个0型文法是否为1型文法
bool isOne() {
    for (size_t i = 0 ; i < principle.size(); i++ ) {
        if (principle[i].left.size() > principle[i].right.size()) {
            return false;
        }
    }
    return true;
}

// 判断一个1型文法是否为2型文法
bool isTwo() {
    for (size_t i = 0; i < principle.size(); i++ ) {
        string left = principle[i].left;
        if (left.size() != 1) return false;
        if (get_type(left[0]) != 1) return false;
    }
    return true;
}

// 判断一个2型文法是否为左线性文法
bool isLeftThree() {
    for (size_t i = 0 ; i < principle.size() ; i++) {
        string right = principle[i].right;
        for (size_t j = 1; j < right.length() ; j++) {
            if (get_type(right[j]) != 2) return false;
        }
    }
    return true;
}

// 判断一个2型文法是否为右线性文法
bool isRightThree() {
    for (size_t i = 0; i < principle.size(); i++) {
        string right = principle[i].right;
        for (size_t j = 0 ; j < right.size() - 1; j++) {
            if (get_type(right[j]) != 2) return false;
        }
    }
    return true;
}

int get_result() {
    if (!isZero()) return -1;
    if (!isOne()) return 0;
    if (!isTwo()) return 1;
    if (isLeftThree()) return 3;
    if (isRightThree()) return 4;
    return 2;
}

void init() {
    VN.clear();
    VT.clear();
    principle.clear();
    memset(type, 0, sizeof(type));
}

int get_type(char ch) {
    return type[ch];
}

bool set_type(char ch, int x) {
    type[ch] = x;
    return true;
}

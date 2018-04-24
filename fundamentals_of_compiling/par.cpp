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

//ֻ���ǲ�����varepsilon�������������Ԫ�ؾ�ֻ����һ����ĸ
vector<char> VN;                 //���ս����
vector<char> VT;                 //�ս����
vector<Principle> principle;     //����ʽ�ļ���
int type[VSIZE];                 //ÿ���ַ�������

void init();              //������
int  get_type(char);      //1�����Ƿ��ս����2�������ս��
bool set_type(char,int);  //����һ���ַ�������
int  get_result();        //���������ķ�������

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
                puts("����ʽ�г���δ֪�ַ�");
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

// �ж��ַ����Ƿ����δ֪�ַ�
bool hasError(const string& s) {
    for ( size_t i = 0 ; i < s.length() ; i++ )
        if ( !get_type(s[i]) ) return true;
    return false;
}

// �ж��Ƿ�Ϊ0���ķ�
bool isZero() {
    for (size_t i = 0; i < principle.size(); i++) {
        if      (hasError(principle[i].left))  return false;
        else if (hasError(principle[i].right)) return false;
    }
    return true;
}

// �ж�һ��0���ķ��Ƿ�Ϊ1���ķ�
bool isOne() {
    for (size_t i = 0 ; i < principle.size(); i++ ) {
        if (principle[i].left.size() > principle[i].right.size()) {
            return false;
        }
    }
    return true;
}

// �ж�һ��1���ķ��Ƿ�Ϊ2���ķ�
bool isTwo() {
    for (size_t i = 0; i < principle.size(); i++ ) {
        string left = principle[i].left;
        if (left.size() != 1) return false;
        if (get_type(left[0]) != 1) return false;
    }
    return true;
}

// �ж�һ��2���ķ��Ƿ�Ϊ�������ķ�
bool isLeftThree() {
    for (size_t i = 0 ; i < principle.size() ; i++) {
        string right = principle[i].right;
        for (size_t j = 1; j < right.length() ; j++) {
            if (get_type(right[j]) != 2) return false;
        }
    }
    return true;
}

// �ж�һ��2���ķ��Ƿ�Ϊ�������ķ�
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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;

class Base {
public:
    virtual void F() { cout << "Base::F" << endl; }
    virtual void G() { cout << "Base::G" << endl; }
    virtual void H() { cout << "Base::H" << endl; }
};

typedef void(*Fun)(void);

int main() {

    Base b;

    int *vtptr = reinterpret_cast<int *>(&b);
    cout << "virtual table address:" <<  vtptr << endl;
    int *first_fun_addr = reinterpret_cast<int *>(*vtptr);
    cout << "first function address in virtual table:" << first_fun_addr << endl;

    Fun fptr = reinterpret_cast<Fun>(*first_fun_addr);
    fptr();

    int *second_fun_addr = reinterpret_cast<int *>(*vtptr + 2);
    fptr = reinterpret_cast<Fun>(*second_fun_addr);
    fptr();

    return 0;
}

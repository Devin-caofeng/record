#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::cout; using std::endl;

class Base0 {
public:
    long base0_;
    Base0() : base0_(0) { }

    virtual void F0() { cout << "Base0::F0()" << endl; }
    virtual void F1() { cout << "Base0::F1()" << endl; }
    virtual void F2() { cout << "Base0::F2()" << endl; }
};

class Base1 {
public:
    long base1_;
    Base1() : base1_(1) { }

    virtual void F0() { cout << "Base1::F0()" << endl; }
    virtual void F1() { cout << "Base1::F1()" << endl; }
    virtual void F2() { cout << "Base1::F2()" << endl; }
};

class Base2 {
public:
    long base2_;
    Base2() : base2_(1) { }

    virtual void F0() { cout << "Base2::F0()" << endl; }
    virtual void F1() { cout << "Base2::F1()" << endl; }
    virtual void F2() { cout << "Base2::F2()" << endl; }
};

class Derive : public Base0, public Base1, public Base2 {
public:
    long derive_;
    Derive() : derive_(9) { }

    virtual void F0() { cout << "Derive::F0()" << endl; }
    virtual void FDerive() { cout << "Derive::FDerive()" << endl; }
};

int main() {

    using Fun = void(*)(void);
    using PtrType = long *;

    Derive d;

    PtrType *vtab_ptr = reinterpret_cast<PtrType *>(&d);

    cout << "[0] Base0::_vptr" << endl;
//    for (int i = 0; vtab_ptr[0][i] != 0; ++i) {
    for (int i = 0; i < 5; ++i) {
        Fun fptr = reinterpret_cast<Fun>(vtab_ptr[0][i]);
        cout << "   [" << i << "] ";
        fptr();
    }

    return 0;
}

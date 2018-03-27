#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;

class Parent {
public:
    long num_in_parent_;
    Parent() : num_in_parent_(0) { }

    virtual void FirstFunc()  { cout << "Parent::FirstFunc()" << endl; }
    virtual void SecondFunc() { cout << "Parent::SecondFunc()" << endl; }
    virtual void ThirdFunc()  { cout << "Parent::ThirdFunc()" << endl; }
};

class Child : public Parent {
public:
    long num_in_child_;
    Child() : num_in_child_(1) { }

    virtual void FirstFunc() { cout << "Child::FirstFunc()" << endl; }
    virtual void ChildSecondFunc() {
        cout << "Child::ChildSecondFunc()" << endl; }
    virtual void ChildThirdFunc() {
        cout << "Child::ChildThirdFunc()" << endl; }
};

class GrandChild : public Child {
public:
    long num_in_grandchild_;
    GrandChild() : num_in_grandchild_(2) { }

    virtual void FirstFunc() { cout << "GrandChild::FirstFunc()" << endl; }
    virtual void ChildSecondFunc() {
        cout << "GrandChild::ChildSecondFunc()" << endl; }
    virtual void GrandChildThirdFunc() {
        cout << "GrandChild::GrandChildThirdFunc()" << endl; }
};

int main() {

    typedef void(*Fun)(void);
    using PtrType = long *;

    GrandChild gc;

    long **vtab_ptr = reinterpret_cast<long **>(&gc);
    cout << "[0] GrandChild::_vptr->" << endl;
    for (int i = 0; reinterpret_cast<Fun>(vtab_ptr[0][i]) != nullptr; ++i) {
        Fun fptr = reinterpret_cast<Fun>(vtab_ptr[0][i]);
        cout << "   [" << i << "]";
        fptr();
    }

    cout << "[1] Parent::num_in_parent_ = "
         << reinterpret_cast<long>(vtab_ptr[1]) << endl;

    cout << "[2] Child::num_in_child_= "
         << reinterpret_cast<long>(vtab_ptr[2]) << endl;

    cout << "[3] GrandChild::num_in_grandchild_= "
         << reinterpret_cast<long>(vtab_ptr[3]) << endl;

    return 0;
}

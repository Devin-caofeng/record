#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class SharedPtr{
public:
    SharedPtr(T *ptr) : ptr_(ptr), cnt_(new int(1)) { }

    SharedPtr(const SharedPtr &ptr) : ptr_(ptr.ptr_), cnt_(ptr.cnt_) {
        ++(*cnt_);
    }

    SharedPtr& operator=(const SharedPtr &ptr) {
        if (this == &ptr) return *this;

        if (!--(*cnt_)) {
            delete ptr_;
            delete cnt_;
            cout << "delete older" << endl;
        }
        ptr_ = ptr.ptr_;
        cnt_ = ptr.cnt_;
        ++(*cnt_);
        return *this;
    }

    ~SharedPtr() {
        --(*cnt_);
        if ((*cnt_) == 0) {
            delete ptr_;
            delete cnt_;
            cout << "delete" << endl;
        }
    }

    T& operator*() { return *ptr_; }

    T* operator->() { return ptr_; }

private:
    T   *ptr_;
    int *cnt_;
};

int main() {
    return 0;
}

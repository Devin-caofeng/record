#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Counter {
public:
    Counter(int u) : cnt_(u) { }
    ~Counter() { }
    int cnt_;
};

template<typename T>
class SharedPtr {
public:
    SharedPtr() : tptr_(nullptr), cntptr_(nullptr) { }

    SharedPtr(T *t) {
        if (t == nullptr) {
            cntptr_ = nullptr;
            tptr_   = nullptr;
            return;
        }
        cntptr_ = new Counter(1);
        tptr_   = t;
    }

private:
    bool IsEmpty() const {
        return tptr_ == nullptr;
    }

    void Clear() {
        if (tptr_ == nullptr) {
            return;
        }

        --cntptr_->cnt_;
        if (cntptr_->cnt_ == 0) {
            delete tptr_;
            delete cntptr_;
        }
        tptr_   = nullptr;
        cntptr_ = nullptr;
    }

    T *tptr_;
    Counter *cntptr_;
};

int main() {



    return 0;
}

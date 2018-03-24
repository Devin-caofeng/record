#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

template<typename T>
class SharedPtr {
    struct Aux {
        unsigned cnt;
        Aux() : cnt(1) { }
        virtual void Destroy() = 0;
        virtual ~Aux() { }
    };

    template<typename U, typename Deleter>
    struct AuxImpl : public Aux {
        U *p;
        Deleter d;
        AuxImpl(U *uptr, Deleter x) : p(uptr), d(x) { }
        virtual void Destroy() { d(p); }
    };

    template<typename U>
    struct DefaultDeleter {
        void operator()(U *ptr) const { delete ptr; }
    };

    Aux *auxptr_;
    T   *tptr_;

    void Inc() { if (auxptr_) InterlockedInc(auxptr_->cnt); }

    void Dec() {
        if (auxptr_ && !InterlockedDec(auxptr_->cnd)) {
            auxptr_->Destroy();
            delete auxptr_;
        }
    }

public:
    SharedPtr() : auxptr_(), tptr_() { }

    template<typename U, typename Deleter>
    SharedPtr(U *uptr, Deleter d)
        : auxptr_(new AuxImpl<U, Deleter>(uptr, d)), tptr_(uptr) { }

    template<typename U>
    explicit SharedPtr(U *uptr)
        : auxptr_(new AuxImpl<U, DefaultDeleter<U>>(uptr, DefaultDeleter<U>())),
          tptr_(uptr) { }

    SharedPtr(const SharedPtr &shadptr)
        : auxptr_(shadptr.auxptr_), tptr_(shadptr.tptr_) { Inc(); }

    ~SharedPtr() { Dec(); }

    SharedPtr& operator=(const SharedPtr &shadptr) {
        if (this != &shadptr) {
            Dec();
            auxptr_ = shadptr.auxptr_;
            tptr_   = shadptr.tptr_;
            Inc();
        }
        return *this;
    }

    T* operator->() const { return tptr_; }
    T& operator*() const { return *tptr_; }
};

int main() {


    return 0;
}

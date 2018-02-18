#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps_(new std::string(s)), i_(0), use_(new size_t(1)) { }
    HasPtr(const HasPtr &hp)
        : ps_(hp.ps_), i_(hp.i_), use_(hp.use_) { ++*use_; }
    HasPtr &operator=(const HasPtr &rhs) {
        ++*rhs.use_;
        if (--*use_ == 0) {
            delete ps_;
            delete use_;
        }
        ps_  = rhs.ps_;
        i_   = rhs.i_;
        use_ = rhs.use_;
        return *this;
    }
    ~HasPtr() {
        if (--*use_ == 0) {
            delete ps_;
            delete use_;
        }
    }

private:
    std::string *ps_;
    int          i_;
    size_t      *use_;
};


int main() {



    return 0;
}

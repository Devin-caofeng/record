#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps_(new std::string(s)), i_(0) { }
    HasPtr(const HasPtr &hp) : ps_(new std::string(*hp.ps_)), i_(hp.i_) { }
    HasPtr &operator=(const HasPtr &rhs_hp) {
        if (this != &rhs_hp) {
            std::string *temp = new std::string(*rhs_hp.ps_);
            delete ps_;
            ps_ = temp;
            i_ = rhs_hp.i_;
        }
        return *this;
    }

    ~HasPtr() { delete ps_; }

private:
    std::string *ps_;
    int i_;
};

int main() {



    return 0;
}

#ifndef EX13_30_HPP_
#define EX13_30_HPP_

#include <iostream>
#include <string>

class HasPtr {
public:
    friend void swap(HasPtr &, HasPtr &);

    HasPtr(const std::string &s = std::string())
        : ps_(new std::string(s)), i_(0) { }

    HasPtr(const HasPtr &hp) : ps_(new std::string(*hp.ps_)), i_(hp.i_) { }

    HasPtr &operator=(const HasPtr &hp) {
        auto new_p = new std::string(*hp.ps_);
        delete ps_;
        ps_ = new_p;
        i_  = hp.i_;

        return *this;
    }

    ~HasPtr() { delete ps_; }

    void Show() { std::cout << *ps_ << '\n'; }

private:
    std::string *ps_;
    int          i_;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
    std::cout << "call swap swap(HasPtr &lhs, HasPtr &rhs)" << '\n';
}

#endif  // EX13_30_HPP_

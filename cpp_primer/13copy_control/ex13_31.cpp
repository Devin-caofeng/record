#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr {
public:
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr &, const HasPtr &);

    HasPtr(const std::string &s = std::string())
        : ps_(new std::string(s)), i_(0) { }

    HasPtr(const HasPtr &hp) : ps_(new std::string(*hp.ps_)), i_(hp.i_) { }

    HasPtr &operator=(HasPtr hp) {
        this->swap(hp);
        return *this;
    }

    ~HasPtr() { delete ps_; }

    void swap(HasPtr &rhs) {
        using std::swap;
        swap(ps_, rhs.ps_);
        swap(i_, rhs.i_);
        std::cout << "call swap(HasPtr &rhs)" << '\n';
    }

    void Show() const { std::cout << *ps_ << '\n'; }

private:
    std::string *ps_;
    int          i_;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    return *lhs.ps_ < *rhs.ps_;
}


int main() {

    std::vector<HasPtr> vec;

    vec.push_back(HasPtr("tom"));
    vec.push_back(HasPtr("jery"));

    std::sort(vec.begin(), vec.end());

    for (const auto &i : vec) i.Show();

    return 0;
}

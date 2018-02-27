#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include "ex13_30.hpp"

class T {
public:
    T() = default;
    T(const T &) = default;
};

class StrVec {
public:
    StrVec() : elements_(nullptr), first_free_(nullptr), cap_(nullptr) { }
    StrVec(const StrVec &);
    StrVec& operator=(const StrVec &);
    ~StrVec() { free(); }

    void   push_back(const std::string &);
    size_t size() const { return first_free_ - elements_; }
    size_t capacity() const { return cap_ - elements_; }
    std::string* begin() const { return elements_; }
    std::string* end() const { return first_free_; }

private:
    static std::allocator<std::string> alloc_;
    void check_n_alloc() { if (size() == capacity()) reallocate(); }

    std::pair<std::string*, std::string*>
    alloc_n_copy(const std::string*, const std::string*);

    void free();
    void reallocate();

private:
    std::string *elements_;
    std::string *first_free_;
    std::string *cap_;
};

void StrVec::push_back(const std::string &s) {
    check_n_alloc();
    alloc_.construct(first_free_++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc_.allocate(e - b);
    return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free() {
    if (elements_) {
        for (auto ptr = first_free_; ptr != elements_; ) {
            alloc_.destroy(--ptr);
        }
        alloc_.deallocate(elements_, cap_ - elements_);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements_ = new_data.first;
    first_free_ = cap_ = new_data.second;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements_ = data.first;;
    first_free_ = cap_ = data.second;

    return *this;
}


int main() {



    return 0;
}

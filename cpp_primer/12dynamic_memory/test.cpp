#include "../need.h"

class StrBlob {
public:
    using size_type = std::vector<std::string>::size_type;

    StrBlob() : data_(std::make_shared<std::vector<std::string>>()) { }
    StrBlob(std::initializer_list<std::string> il)
        : data_(std::make_shared<std::vector<std::string>>(il)) { };
    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty(); }

    void push_back(const std::string &str) { data_->push_back(str); }
    void pop_back();

    // 元素访问
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data_;
    void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data_->size()) {
        throw std::out_of_range(msg);
    }
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data_->pop_back();
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data_->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data_->back();
}

const std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data_->back();
}

const std::string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data_->back();
}


int main() {

    // const StrBlob cstr({ "hello" });
    // StrBlob str({ "hello", "lambda", "fork" });

    // std::cout << (str.front() = "lambda") << '\n';
    // std::cout << cstr.front() << '\n';

    char c[0];
    // c[0] = 'c';
    std::cout << "c size : " << sizeof(c) << '\n';
    std::cout << '[' << c[0] << ']' << '\n';

    char *cp = new char[0];
    cp[0] = 'c';
    *cp = 'p';
    std::cout << '[' << cp[0] << ']' << '\n';

    return 0;
}

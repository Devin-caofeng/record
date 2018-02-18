#include <iostream>

class Numbered {
public:
    Numbered() { mysn_ = ++unique; }
    Numbered(const Numbered &) : mysn_(++unique) { }

    int mysn_;
    static int unique;
};

int Numbered::unique = 10;

void F(const Numbered &s) {
    std::cout << s.mysn_ << '\n';
}

int main() {

    Numbered a, b = a, c = b;

    F(a);
    F(b);
    F(c);

    return 0;
}

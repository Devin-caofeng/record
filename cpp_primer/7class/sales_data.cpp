#include "../need.h"

class SalesData {
public:
    friend SalesData Add(const SalesData &, const SalesData &);
    friend std::istream &Read(std::istream &, SalesData &);
    friend std::ostream &Print(std::ostream &, SalesData &);

    SalesData() = default;
    SalesData(const std::string &s) : book_no_(s) { }
    SalesData(const std::string &s, unsigned n, double p)
        : book_no_(s), units_sold_(n), revenue_(p * n) { }
    SalesData(std::istream &);

    std::string IsBN() const { return book_no_; }
    SalesData &Combine(const SalesData &);
    double AvgPrice() const;

private:
    std::string book_no_;
    unsigned int units_sold_ = 0;
    double revenue_ = 0.0;
};

SalesData Add(const SalesData &, const SalesData &);
std::ostream &Print(std::ostream &, const SalesData &);
std::istream &Read(std::istream &, SalesData &);

// .cpp 文件
double SalesData::AvgPrice() const {
    if (units_sold_) return revenue_ / units_sold_;
    else return 0;
}

SalesData &SalesData::Combine(const SalesData &rhs) {
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this;
}

SalesData Add(const SalesData &lhs, const SalesData &rhs) {
    SalesData sum = lhs;
    sum.Combine(rhs);
    return sum;
}

std::istream &Read(std::istream &is, SalesData &item) {
    double price = 0.0;
    is >> item.book_no_ >> item.units_sold_ >> price;
    item.revenue_ = price * item.units_sold_;
    return is;
}

std::ostream &Print(std::ostream &os, SalesData &item) {
    os << item.IsBN() << " "
       << item.units_sold_ << " "
       << item.revenue_ << " "
       << item.AvgPrice();
    return os;
}

int main() {

    const SalesData s;
    s.IsBN();

    return 0;
}

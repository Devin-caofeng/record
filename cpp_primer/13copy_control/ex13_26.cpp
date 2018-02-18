#include <iostream>
#include <string>
#include "ex13_26.hpp"

ConstStrBlobPtr StrBlob::Begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::End() const {
    return ConstStrBlobPtr(*this, data_->size());
}

StrBlob &StrBlob::operator=(const StrBlob &sb) {
    data_ = std::make_shared<vector<string>>(*sb.data_);
    return *this;
}

int main() {



    return 0;
}

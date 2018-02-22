#include "ex12_22.hpp"

ConstStrBlobPtr StrBlob::Begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::End() const {
    return ConstStrBlobPtr(*this, data_->size());
}

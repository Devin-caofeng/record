#include "ex12_19.hpp"

StrBlobPtr StrBlob::Begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::End() {
    return StrBlobPtr(*this, data_->size());
}

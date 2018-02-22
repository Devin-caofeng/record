#include <fstream>
#include <iostream>
#include "ex12_19.hpp"


int main() {

    std::ifstream ifs("ex12_19.cpp");

    StrBlob blob;
    for (std::string str; getline(ifs, str); ) {
        blob.PushBack(str);
    }

    for (StrBlobPtr beg(blob.Begin()), end(blob.End());
            beg != end; beg.Incr()) {
        std::cout << beg.Deref() << '\n';
    }

    return 0;
}

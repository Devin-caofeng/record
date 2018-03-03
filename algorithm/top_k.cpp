#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "./comm.hpp"
using std::vector;
using std::string;

void TopK(vector<int> &bigs) {
    make_heap(bigs.begin(), bigs.end(), std::greater<int>());
    for (int i = 0; i < 100000000; ++i) {
        int r = rand() % 100000;
        if (r > bigs.front()) {
            // set the smallest one to the end
            pop_heap(bigs.begin(), bigs.end(), std::greater<int>());
            // remove the last/smallest one
            bigs.pop_back();
            // add to the last one
            bigs.push_back(r);
            // mask heap again, the first one is still the smallest one
            push_heap(bigs.begin(), bigs.end(), std::greater<int>());
        }
    }

    sort_heap(bigs.begin(), bigs.end(), std::greater<int>());
}

int main() {
    int k = 10;
    vector<int> bigs(k, 0);
    std::cout << bigs.size() << std::endl;

    TopK(bigs);

    PrintContainer(bigs);

    return 0;
}

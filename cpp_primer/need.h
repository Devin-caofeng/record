#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iterator>


template <typename T>
inline void PrintSeqContainer(const T &container) {
    for (const auto &i : container) std::cout << i << ' ';
    std::cout << std::endl;
}

template <typename T>
inline void PrintByIter(T curr, T end) {
    for (; curr!= end; ++curr) std::cout << *curr << ' ';
    std::cout << std::endl;
}

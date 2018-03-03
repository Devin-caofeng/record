#ifndef COMM_HPP_
#define COMM_HPP_

#include <iostream>
#include <vector>

template <typename T>
void PrintContainer(T &container) {
    for (const auto &it : container) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}


#endif  // COMM_HPP_

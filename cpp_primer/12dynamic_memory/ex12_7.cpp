#include "../need.h"

void Input(std::shared_ptr<std::vector<int>> );
void Print(std::shared_ptr<std::vector<int>> );


int main() {

    auto vec_ptr = std::make_shared<std::vector<int>>();

    Input(vec_ptr);
    Print(vec_ptr);

    return 0;
}


void Input(std::shared_ptr<std::vector<int>> vec_ptr) {
    int num;
    while (std::cin >> num) {
        vec_ptr->push_back(num);
    }
}

void Print(std::shared_ptr<std::vector<int>> vec_ptr) {
    for (const auto &i : *vec_ptr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

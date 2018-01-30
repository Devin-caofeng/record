#include "../need.h"

std::vector<int> *Input(std::vector<int> *);
void Print(std::vector<int> *);


int main() {


    std::vector<int> *vec_ptr = new std::vector<int>();

    Print(Input(vec_ptr));

    delete vec_ptr;

    return 0;
}


std::vector<int> *Input(std::vector<int> *vec_ptr) {
    int num;
    while (std::cin >> num) {
        vec_ptr->push_back(num);
    }

    return vec_ptr;
}

void Print(std::vector<int> *vec_ptr) {
    for (const auto &i : *vec_ptr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

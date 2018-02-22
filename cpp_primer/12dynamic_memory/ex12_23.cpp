#include <iostream>
#include <string>
#include <cstring>


int main() {

    char *concatenate_str = new char[strlen("hello world") + 1]();
    strcat(concatenate_str, "hello ");
    strcat(concatenate_str, "world");
    std::cout << concatenate_str << '\n';
    delete[] concatenate_str;

    std::string str1{ "hello " };
    std::string str2{ "world" };
    std::cout << str1 + str2 << '\n';

    return 0;
}

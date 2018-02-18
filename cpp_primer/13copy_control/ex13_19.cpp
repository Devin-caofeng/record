#include <iostream>
#include <string>

class Employee {
public:
    Employee() : name_(std::string("tom")), id_(++seed) { }
    Employee(const std::string &name) : name_(name), id_(++seed) { }
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

private:
    std::string name_;
    int id_;
    static int seed;
};

int Employee::seed = 10;


int main() {



    return 0;
}

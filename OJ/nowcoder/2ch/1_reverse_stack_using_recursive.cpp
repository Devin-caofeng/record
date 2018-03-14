#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using std::vector;
using std::string;
using std::stack;

class Solution {
public:
    void reverse(stack<int> s) {
        if (s.empty()) return;

        int i = s.top();
        s.pop();
        reverse(s);
        s.push(i);
    }

    int getAndRemoveLastElement(stack<int> s) {
        int num = s.top();
        s.pop();
        if (s.empty()) {
            return num;
        }
        else {
            int last = getAndRemoveLastElement(s);
            s.push(num);
            return last;
        }
    }
};

template <typename T>
void Print(const T &container) {
    for (const auto &iter : container) {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
}

void test(stack<int> my) {
    Solution s;
    s.reverse(my);
}

int main() {

    vector<int> vec{ 1, 2, 3, 4 };
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    test(s);

    while (s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}

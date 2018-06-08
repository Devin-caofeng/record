#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 1) return atoi(tokens[0].c_str());

        stack<int> stk;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" &&
                    tokens[i] != "*" && tokens[i] != "/") {
                stk.push(atoi(tokens[i].c_str()));
            }
            else {
                int m = stk.top(); stk.pop();
                int n = stk.top(); stk.pop();
                if (tokens[i] == "+") stk.push(n + m);
                else if (tokens[i] == "-") stk.push(n - m);
                else if (tokens[i] == "*") stk.push(n * m);
                else if (tokens[i] == "/") stk.push(n / m);
            }
        }

        return stk.top();
    }
};

int main() {
    return 0;
}

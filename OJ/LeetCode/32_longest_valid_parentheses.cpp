#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidParenthese(string s) {
    stack<int> stk;
    stk.push(-1);
    size_t ret = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        int tmp = stk.top();
        if (tmp != -1 && s[i] == ')' && s[tmp] == '(') {
            stk.pop();
            ret = max(ret, i - stk.top());
        }
        else {
            stk.push(i);
        }
    }

    return ret;
}

int longestValidParenthese_err(string s) {
    stack<char> stk;
    size_t cur_cnt = 0, max_cnt = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk.push('(');
        }
        else if (!stk.empty()) {
            stk.pop();
            cur_cnt += 2;
            max_cnt = max(cur_cnt, max_cnt);
        }
        else {
            cur_cnt = 0;
        }
    }
    return max_cnt;
}

int main() {
    return 0;
}

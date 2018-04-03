#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);

    while (getline(ss, tmp, '/')) {
        if (tmp == "" || tmp == ".") continue;
        if (tmp == ".." && !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for (auto str : stk) res += "/" + str;
    return res.empty() ? "/" : res;
}

int main() {
    return 0;
}

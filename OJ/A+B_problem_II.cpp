#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    int cnt = 0;

    while (cnt++ < n) {
        string a, b;
        cin >> a >> b;

        // 翻转 a b 简化后续处理
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry_flag = 0;
        vector<int> ret;

        decltype(a.size()) i;
        for (i = 0; i < a.size() && i < b.size(); ++i) {
            int sum = (a[i] - '0') + (b[i] - '0');
            if (sum > 9 || (sum == 9 && carry_flag == 1)) {
                ret.push_back((sum + carry_flag) % 10);
                carry_flag = 1;
            } else {
                ret.push_back(sum + carry_flag);
                carry_flag = 0;
            }
        }

        if (i == a.size()) {
            for (; i < b.size(); ++i) {
                if (b[i] == '9' && carry_flag == 1) {
                    ret.push_back(0);
                    carry_flag = 1;
                } else {
                    ret.push_back((b[i] - '0') + carry_flag);
                    carry_flag = 0;
                }
            }
        } else if (i == b.size()) {
            for (; i < a.size(); ++i) {
                if (a[i] == '9' && carry_flag == 1) {
                    ret.push_back(0);
                    carry_flag = 1;
                } else {
                    ret.push_back((a[i] - '0') + carry_flag);
                    carry_flag = 0;
                }
            }
        }

        if (i == a.size() && i == b.size() && carry_flag == 1)
            ret.push_back(carry_flag);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout << "Case " << cnt << ":" << endl;
        cout << a << " + " << b << " = ";
        for (auto iter = ret.crbegin(); iter != ret.crend(); ++iter)
            cout << *iter;
        cout << endl;
        if (cnt < n)
            cout << endl;
    }

    return 0;
}

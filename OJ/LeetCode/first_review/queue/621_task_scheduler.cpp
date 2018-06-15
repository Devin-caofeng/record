#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnt(26, 0);
    for (char task : tasks) {
        ++cnt[task - 'A'];
    }

    int max_cnt = *max_element(cnt.cbegin(), cnt.cend());
    int res = (max_cnt - 1) * (n + 1);

    res += count_if(cnt.cbegin(), cnt.cend(), [max_cnt](int cur_cnt) {
        return cur_cnt == max_cnt;
    });

    return max(res, static_cast<int>(tasks.size()));
}

namespace N1 {

int leastInterval(vector<char>& tasks, int n) {
    int res = 0, cycle = n + 1;
    unordered_map<char, int> unmp;
    priority_queue<int> pri_que;

    for (char task : tasks) {
        ++unmp[task];
    }
    for (auto pr : unmp) {
        pri_que.push(pr.second);
    }

    while (!pri_que.empty()) {
        int cnt = 0;
        vector<int> tmp;
        for (int i = 0; i < cycle; ++i) {
            if (!pri_que.empty()) {
                tmp.push_back(pri_que.top());
                pri_que.pop();
                ++cnt;
            }

            for (int val : tmp) {
                if (--val > 0) pri_que.push(val);
            }

            res += pri_que.empty() ? cnt : cycle;
        }
    }

    return res;
}

}

int main() {
    return 0;
}

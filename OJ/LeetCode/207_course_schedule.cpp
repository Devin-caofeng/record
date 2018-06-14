#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in_degree(numCourses, 0);

        for (const auto& request : prerequisites) {
            g[request.second].push_back(request.first);
            ++in_degree[request.first];
        }

        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) que.push(i);
        }

        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            for (auto citer = g[cur].cbegin();
                    citer != g[cur].cend(); ++citer) {
                if (--in_degree[*citer] == 0) que.push(*citer);
            }
        }

        for (const auto& val : in_degree) {
            if (val != 0) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}

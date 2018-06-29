#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<pair<int, int>>
    reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const pair<int, int>& a,
                                              const pair<int, int>& b) {
            return a.first > b.first ||
                   (a.first == b.first && a.second < b.second);
        });

        vector<pair<int, int>> res;
        for (const auto& p : people) {
            res.insert(res.begin() + p.second, p);
        }

        return res;
    }
};

int main() {
    return 0;
}

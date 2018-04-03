#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void genSubsets(vector<int>& nums, int start, vector<int>& sub,
                vector<vector<int>>& subs) {
    subs.push_back(sub);
    for (size_t i = start; i < nums.size(); ++i) {
        sub.push_back(nums[i]);
        genSubsets(nums, i + 1, sub, subs);
        sub.pop_back();
    }
}

vector<vector<int>> subsets_recur(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs;
    vector<int> sub;
    genSubsets(nums, 0, sub, subs);
    return subs;
}

vector<vector<int>> subsets_itera(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs(1, vector<int>());
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = 0; j < subs.size(); ++j) {
            subs.push_back(subs[j]);
            subs.back().push_back(nums[i]);
        }
    }
    return subs;
}

vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int elem_num = nums.size();
    int subset_num = pow(2, elem_num);
    vector<vector<int>> subset_set(subset_num, vector<int>());

    for (int i = 0; i < elem_num; ++i) {
        for (int j = 0; j < subset_num; ++j) {
            if ((j >> i) & 1) subset_set[j].push_back(nums[i]);
        }
    }
    return subset_set;
}

int main() {
    return 0;
}

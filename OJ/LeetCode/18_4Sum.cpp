#include "../need.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> FourSum(vector<int> &nums, int target) {
        vector<vector<int>> total;
        int n = static_cast<int>(nums.size());
        if (n < 4) return total;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n- 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j+1]+nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[n-2]+nums[n-1] < target) continue;

                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum < target) ++left;
                    else if (sum > target) --right;
                    else {
                        total.push_back({nums[i], nums[j],
                                nums[left], nums[right]});
                        do {
                            ++left;
                        } while (nums[left] == nums[left-1] && left < right);
                        do {
                            --right;
                        } while (nums[right] == nums[right+1] && left < right);
                    }
                }
            }
        }

        return total;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;

                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back({nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }

        return total;
        // if (nums.size() < 4) return vector<vector<int>>();

        // vector<int> alloc;
        // int len = static_cast<int>(nums.size());
        // for (int i = 0; i < len - 3; ++i) {
        //     alloc.push_back(nums[i] + nums[i + 1]);

        // }

        // for (auto i : alloc) cout << i << ' ';
        // cout << '\n';

        // vector<vector<int>> result;
        // for (int i = 2; i < len - 1; ++i) {
        //     int request = target - alloc[i - 2];
        //     for (int j = i + 1; j < len; ++j) {
        //         if (nums[i] + nums[j] == request) {
        //             result.push_back({ nums[i - 2], nums[i - 1],
        //                                nums[i], nums[j] });
        //         }
        //     }
        // }
        // return result;
    }
};

int main() {

    vector<int> vec = { 1, 0, -1, 0, -2, 2 };
    Solution s;
    auto vvec = s.FourSum(vec, 0);

    for (auto i : vvec) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}

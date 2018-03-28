#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using std::string; using std::vector;
using std::cout; using std::endl;
using std::unordered_map;
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        unordered_map<string, multiset<string> mp;
        for (string s : strs) {
            string t = strSort(s);
            mp[t].insert(s);
        }
    }

    string strSort(string s) {
        int cnt[26] = { 0 }, n = s.size();
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }

        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; ++j) {
            for (int i = 0; i < cnt[j]; ++i) {
                t[p++] += j;
            }
        }
        return t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<int, int> str_index;
        int cnt = 0;
        for (const auto& iter : strs) {
            str_index[getStrSum(iter)] = cnt;
        }

        vector<vector<string>> ret(cnt, vector<string>());
        for (const auto& iter : strs) {
            ret[str_index[getStrSum(iter)]].push_back(iter);
        }

        return ret;
    }

    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>::iterator> cache;
        vector<string> ret;
        for (auto iter = strs.begin(); iter != strs.end(); ++iter) {
            string temp(*iter);
            std::sort(temp.begin(), temp.end());

            auto found = cache.find(temp);
            if (found == cache.end()) {
                cache[temp] = iter;
            }
            else {
                ret.push_back(*iter);
                if (found->second != strs.end()) {
                    ret.push_back(*found->second);
                    found->second = strs.end();
                }
            }
        }
        return ret;
    }

private:
    int getStrSum(const string& s) {
        int sum = 0;
        for (const auto& ch : s) {
            sum += ch - 'a';
        }
        return sum;
    }
};

int main() {

    return 0;
}

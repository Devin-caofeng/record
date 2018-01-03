#include "../need.h"
using namespace std;

int lengthOfLongestSubstring(string s) {
    using str_size = string::size_type;

    map<char, str_size> hash;  // 当前字母到其在该字符串中最后一次出现位置的映射
    str_size max = 0;
    str_size begin = 0;

    for (str_size i = 0; i < s.size(); ++i) {
        if (hash[s[i]] == 0 || (hash[s[i]] != 0 && begin > hash[s[i]]))
            max = (max > (i - begin + 1)) ? max : (i - begin + 1);
        else
            begin = hash[s[i]];
        hash[s[i]] = i + 1;
    }

    return max;
}

int solutionTwo(string str) {
    int n = str.size();
    int ans = 0;
    int vec[128] = { 0 };

    for (int i = 0, j = 0; j < n; ++j) {
        i = max(vec[static_cast<int>(str[j])], i);
        ans = max(ans, j - i + 1);
        vec[static_cast<int>(str[j])] = j + 1;
    }

    return ans;
}

int main() {



    return 0;
}

#if 0            // 错误
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int length = 0;
        int max_length = 0;

        auto start_pos = mp.begin();
        for (decltype(s.size()) i = 0; i < s.size(); ++i) {
            auto pos = mp.find(s[i]);
            if (pos != mp.end()) {
                auto next_pos = ++pos;
                int start = start_pos->second;
                int end = 0;//next_pos->second;
                mp.erase(start_pos, next_pos);
                length -= (end - start);

                mp.insert( {s[i], i}  );
                ++length;
                //start_pos = next_pos;
                //
            }
            else {
                mp.insert( {s[i], i}  );
                ++length;
                if (length > max_length)
                    max_length = length;

            }

        }

        return max_length;
    }
};

#endif

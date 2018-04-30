#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> fullJustify_2(vector<string> &words, int maxWidth) {
    vector<string> res;
    int i = 0;
    while (i < words.size()) {
        int j = i, len = 0;
        while (j < words.size() && len + words[j].size() + j - i <= maxWidth) {
            len += words[j++].size();
        }

        string tmp;
        int space = maxWidth - len;
        for (int k = i; k < j; ++k) {
            tmp += words[k];
            if (space > 0) {
                int cnt;
                if (j == words.size()) {
                    if (j - k == 1) cnt = space;
                    else cnt = 1;
                }
                else {
                    if (j - k - 1 > 0) {
                        if (space % (j - k - 1) == 0) cnt = space / (j - k - 1);
                        else cnt = space / (j - k - 1) + 1;
                    }
                    else {
                        tmp = space;
                    }
                }
                tmp.append(cnt, ' ');
                space -= cnt;
            }
        }
        res.push_back(tmp);
        i = j;
    }

    return res;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;

    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() &&
                       l + words[i+k].size() <= maxWidth - k; k++) {
            l += words[i+k].size();
        }

        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if (i + k >= words.size()) tmp += " ";
            else tmp += string((maxWidth - l) / (k - 1) +
                               (j < (maxWidth - l) % (k - 1)), ' ');
            tmp += words[i+j+1];

        }
        tmp += string(maxWidth - tmp.size(), ' ');
        res.push_back(tmp);
    }

    return res;
}

int main() {
    return 0;
}

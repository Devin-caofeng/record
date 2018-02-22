#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    vector<int> GetLeastNumbers(vector<int> input, int k) {
        vector<int> ret;
        if (k > input.size()) {
            return ret;
        }

        int s = 0, e = input.size() - 1;
        int index = -1;
        while (index != k - 1) {
            if (index > (k - 1)) {
                e = index - 1;
            }
            else {
                s = index + 1;
            }
            index = Partition(input, s, e);
        }

        for (const auto &i : input) {
            ret.push_back(i);
        }

        return ret;
    }

    int Partition(vector<int> &input, int s, int e) {
        int j = s - 1;
        int cmp = input[e];
        for (int i = s; i < e; ++i) {
            if (input[i] < cmp) {
                std::swap(input[i], input[++j]);
            }
        }
        std::swap(input[e], input[++j]);

        return j;
    }
};


int main() {



    return 0;
}

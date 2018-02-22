#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    int InversePairs(vector<int> data) {
        size_t len = data.size();
        if (len <= 0) return 0;

        vector<int> copy;
        for (const auto &i : data) copy.push_back(i);

        long long count = DoInversePairs(data, copy, 0, len - 1);

        return count % 1000000007;
    }

    long long DoInversePairs(vector<int> &data, vector<int> &copy,
                             int start, int end) {
        if (start == end) {
            copy[start] = data[start];
            return 0;
        }

        int len = (end - start) / 2;
        long long left = DoInversePairs(copy, data, start, start + len);
        long long right = DoInversePairs(copy, data, start + len + 1, end);

        int i = start + len;
        int j = end;
        int index_copy = end;
        long long count = 0;
        while (i >= start && j >= start + len + 1) {
            if (data[i] > data[j]) {
                copy[index_copy--] = data[i--];
                count = count + j - start - len;
            }
            else {
                copy[index_copy--] = data[j--];
            }
        }
        for ( ; i >= start; --i)           copy[index_copy--] = data[i];
        for ( ; j >= start + len + 1; --j) copy[index_copy--] = data[j];

        return left + right + count;
    }
};

int main() {



    return 0;
}

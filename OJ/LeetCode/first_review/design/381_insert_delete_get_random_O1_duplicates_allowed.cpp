#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class RandomizedCollection {
public:
    RandomizedCollection() { }

    bool insert(int val) {
        bool ret = index_.find(val) == index_.end();
        index_[val].insert(output_.size());
        output_.emplace_back(val);
        return ret;
    }

    bool remove(int val) {
        if (index_.find(val) == index_.end()) return false;

        int last = output_.back();
        output_.pop_back();
        index_[last].erase(output_.size());

        if (last != val) {
            int i = *index_[val].begin();
            index_[val].erase(i);
            index_[last].insert(i);
            output_[i] = last;
        }
        if (index_[val].empty()) index_.erase(val);

        return true;
    }

    int getRandom() {
        return output_[rand() % output_.size()];
    }

private:
    vector<int> output_;
    unordered_map<int, unordered_set<int>> index_;
};

int main() {
    return 0;
}

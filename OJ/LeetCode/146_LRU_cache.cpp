#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) { }

    int get(int key) {
        auto iter = mp_.find(key);
        if (iter == mp_.end()) return -1;
        lst_.splice(lst_.begin(), lst_, iter->second);

        return iter->second->second;
    }

    void put(int key, int value) {
        auto iter = mp_.find(key);
        if (iter != mp_.end()) lst_.erase(iter->second);
        lst_.push_front(make_pair(key, value));
        mp_[key] = lst_.begin();

        if (mp_.size() > cap_) {
            int k = lst_.rbegin()->first;
            lst_.pop_back();
            mp_.erase(k);
        }
    }

private:
    size_t cap_;
    list<pair<int, int>> lst_;
    unordered_map<int, list<pair<int, int>>::iterator> mp_;
};

int main() {
    return 0;
}

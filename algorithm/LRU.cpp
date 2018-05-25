#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) { }

    int get(int key) {
        if (pos_.find(key) != pos_.end()) {
            put(key, pos_[key]->second);
            return pos_[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (pos_.find(key) != pos_.end()) {
            recent_.erase(pos_[key]);
        }
        else if (recent_.size() >= capacity_) {
            pos_.erase(recent_.back().first);
            recent_.pop_back();
        }
        recent_.push_front({ key, value });
        pos_[key] = recent_.begin();
    }

private:
    size_t capacity_;
    list<pair<int, int>> recent_;
    unordered_map<int, list<pair<int, int>>::iterator> pos_;
};

int main() {
    return 0;
}

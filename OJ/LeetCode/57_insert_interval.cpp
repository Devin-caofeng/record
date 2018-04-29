#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) { }
    Interval(int s, int e) : start(s), end(e) { }
};

vector<Interval> insert_2(vector<Interval> &intervals, Interval newInterval) {
    auto res = intervals;

    auto low = lower_bound(res.cbegin(), res.cend(), newInterval,
        [](const Interval &lhs, const Interval &rhs) {
            return lhs.start < rhs.start;
    });
    if (low != res.cbegin() && std::prev(low)->end >= newInterval.start) {
        --low;
        newInterval.start = low->start;
    }

    auto up = lower_bound(res.cbegin(), res.cend(), newInterval,
        [](const Interval &lhs, const Interval &rhs) {
            return lhs.end < rhs.end;
    });
    if (up != res.cend() && up->start <= newInterval.end) {
        newInterval.end = up->end;
        ++up;
    }

    auto insert_pos = res.erase(low, up);
    res.insert(insert_pos, newInterval);

    return res;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    size_t i = 0;
    while (i < intervals.size() && intervals[i].end < newInterval.start) {
        res.push_back(intervals[i++]);
    }

    while (i < intervals.size() && intervals[i].start <= newInterval.end) {
        newInterval.start = min(intervals[i].start, newInterval.start);
        newInterval.end = max(intervals[i].end, newInterval.end);
        ++i;
    }
    res.push_back(newInterval);

    while (i < intervals.size()) {
        res.push_back(intervals[i++]);
    }

    return res;
}

int main() {
    return 0;
}

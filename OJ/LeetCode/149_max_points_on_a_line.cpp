#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) { }
    Point(int a, int b) : x(a), y(b) { }
};

class Solution{
public:
    int maxPoint(vector<Point> &points) {
        int res = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> mp;
            int samePoint = 1;

            for (size_t j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++samePoint;
                    continue;
                }

                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int d = gcd(dx, dy);
                ++mp[make_pair(dx / d, dy / d)];
            }

            res = max(res, samePoint);
            for (const auto &pr : mp) {
                res = max(res, pr.second + samePoint);
            }
        }

        return res;
    }

private:
    int gcd(int x, int y) {
        while (y) {
            int r = x % y;
            x = y;
            y = r;
        }

        return x;
    }
};


class Solution_TimeLimit {
public:
    int maxPoint(vector<Point> &points) {
        int res = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            int samePoint = 1;
            unordered_map<double, int> mp;

            for (size_t j = i + 1; j < points.size(); ++i) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++samePoint;
                }
                else if (points[i].x == points[j].x) {
                    ++mp[INT_MAX];
                }
                else {
                    double slope = double(points[i].y - points[j].y) /
                                   double(points[i].x - points[j].x);
                    ++mp[slope];
                }
            }

            int localMax = 0;
            for (const auto &p : mp) {
                localMax = max(localMax, p.second);
            }
            localMax += samePoint;

            res= max(res, localMax);
        }

        return res;
    }
};

int main() {
    return 0;
}

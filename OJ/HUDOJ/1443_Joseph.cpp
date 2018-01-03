#include <iostream>
#include <cstdio>
using namespace std;

bool joseph(int m, int n) {
    int k = m / 2;
    int p = 0;

    while (m > k) {
        p += n % m;
        p %= m;

        if (p > k) {
            --p;
            --m;
        } else if (p == 0) {
            p = --m;
        } else {
            return false;
        }
    }
    return true;
}


int main() {

    int ans[14];
    int m;
    for (int i = 1; i <= 13; ++i) {
        for (int j = i + 1; ; ++j) {
            if (joseph(i * 2, j)) {
                ans[i] = j;
                break;
            }
        }
    }

    while (scanf("%d", &m) && m)
        printf("%d\n", ans[m]);

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

void Cla(int n) {
    // 格式控制
    printf("n e\n");
    printf("- ");
    for (int i = 0; i < n + 2; ++i) printf("-");
    printf("\n");

    double tmp = 1;
    double ret = 0;

    for (int i = 0; i <= n; ++i) {
        if (i == 0) tmp *= 1;
        else tmp *= i;
        ret += 1 / tmp;

        if (i > 2) printf("%d %.9f\n", i, ret);
        else printf("%d %g\n", i, ret);
    }
}

int main() {

    Cla(9);

    return 0;
}

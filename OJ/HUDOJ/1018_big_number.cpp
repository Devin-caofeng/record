#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;

    while (n--) {
        int c;
        cin >> c;
        double sum = 0;
        for (int i = 1; i <= c; ++i) {
            sum += log10(i);
        }
       cout << static_cast<int>(sum + 1) << endl;
    }

    return 0;
}

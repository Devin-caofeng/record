#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

int main() {

    for (string str; std::cin >> str; ) {
        vector<int> used(10, 0);
        int digit = -1, the_min = 0x3f3f3f3f;
        for (const auto &iter : str) {
            ++used[iter - '0'];
        }

        for (int i = 1; i < 10; ++i) {
            if (the_min > used[i]) {
                the_min = used[i];
                digit = 1;
            }
        }
        if (used[0] + 1 <= the_min) {
            std::cout << "1" << string(the_min, '0') << std::endl;
        }
        else {
            std::cout << string(the_min + 1, digit + '0') << std::endl;
        }
    }

    return 0;
}

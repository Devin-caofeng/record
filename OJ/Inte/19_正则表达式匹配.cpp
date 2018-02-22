#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

bool DoMatch(const char *str, const char *pattern);

bool Match(const char *str, const char *pattern) {
    if (str == nullptr || pattern == nullptr) return false;

    return DoMatch(str, pattern);
}

bool DoMatch(const char *str, const char *pattern) {
    if (*str == '\0' && *pattern == '\0') return true;
    if (*str != '\0' && *pattern == '\0') return false;

    if (*(pattern + 1) == '*') {
        if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
            return DoMatch(str + 1, pattern + 2) ||
                   DoMatch(str + 1, pattern) ||
                   DoMatch(str, pattern + 2);
        }
        else {
            // 略过一个 '*'
            return DoMatch(str, pattern + 2);
        }
    }

    if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return DoMatch(str + 1, pattern + 1);
    }

    return false;
}

int main() {



    return 0;
}

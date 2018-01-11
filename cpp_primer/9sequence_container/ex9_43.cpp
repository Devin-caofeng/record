#include "../need.h"

void StrReplace(std::string &s,
                const std::string &old_val,
                const std::string &new_val) {
    for (auto cur = s.begin(); cur < s.end() - old_val.size(); ) {
        if (old_val == std::string(cur, cur + old_val.size())) {
            cur = s.erase(cur, cur + old_val.size());
            cur = s.inset(std::string::const_iterator(cur),
                           new_val.begin(), new_val.end());
            cur += new_val.size();
        }
        else {
            ++cur;
        }
    }
}

int main() {



    return 0;
}

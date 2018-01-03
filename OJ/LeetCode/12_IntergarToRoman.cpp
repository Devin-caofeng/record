#include "../need.h"

class Solution {
public:
    std::string IntToRoman(int num) {
        static const std::string roman_num[4][10] = {
            { "","I","II","III","IV","V","VI","VII","VIII","IX" },
            { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
            { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
            { "","M","MM","MMM" },
        };

        return roman_num[3][num / 1000] + roman_num[2][(num / 100) % 10] +
               roman_num[1][(num / 10) % 10] + roman_num[0][num % 10];
    }
};

int main() {

    Solution s;
    std::cout << s.IntToRoman(100) << std::endl;

    return 0;
}

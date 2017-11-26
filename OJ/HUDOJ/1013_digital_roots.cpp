//#include "../need.h"
#include <iostream>
using namespace std;

int main() {

    string s;
    cin >> s;

    while (s != "0") {
        while (true) {
            int sum = 0;
            for (string::size_type i = 0; i < s.size(); ++i)
                sum += (s[i] - '0');

            s = to_string(sum);

            if (sum <= 9)
                break;
//            cout << s << endl;
        }
        cout << s[0] << endl;

        cin >> s;
    }

    return 0;
}


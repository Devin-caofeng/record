#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string; using std::vector;
using std::cout; using std::endl;
int main() {

    int n = 0x80000000;
    long absn = n;
    cout << n << endl << -n << endl;
    cout << -absn << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using std::vector;
using std::string;
using namespace std;

void _DispalyCategory(random_access_iterator_tag) {
    cout << "random_access_iterator" << endl;
}

template<typename I>
void DisplayCategory(I) {
    typename std::iterator_traits<I>::iterator_category category;
    _DispalyCategory(category);
}

int main() {

    DisplayCategory(vector<int>::iterator());

    return 0;
}

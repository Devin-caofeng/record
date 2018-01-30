#include "../need.h"
using namespace std;

void WordTransform(ifstream &map_file, ifstream &input);
auto BulidMap(ifstream &map_file) -> map<string, string>;
const string &Transform(const string &word,
                        const map<string, string> &trans_map);


int main() {



    return 0;
}

void WordTransform(ifstream &map_file, ifstream &input) {
    auto trans_map = BulidMap(map_file);

    for (string text; getline(input, text); ) {
        istringstream iss(text);
        for (string word; iss >> word; ) {
            cout << Transform(word, trans_map) << ' ';
        }
        cout << '\n';
    }
}

auto BulidMap(ifstream &map_file) -> map<string, string>{
    map<string, string> trans_map;

    for (string key, value; map_file >> key && getline(map_file, value); ) {
        if (value.size() > 1) {
            trans_map[key] =
                value.substr(1).substr(0, value.find_last_not_of(' '));
        }
    }

    return trans_map;
}

const string &Transform(const string &word,
                        const map<string, string> &trans_map) {
    auto iter = trans_map.find(word);
    return iter != trans_map.cend() ? iter->second : word;
}

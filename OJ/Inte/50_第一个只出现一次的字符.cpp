#include <iostream>
using namespace std;

int FirstNotRepeatingChar(const char *str) {
    if (str == nullptr) return -1;

    const size_t table_size = 256;
    size_t hash_table[table_size];
    for (size_t i = 0; i < table_size; ++i) hash_table[i] = 0;

    const char *hash_key = str;
    while (*(hash_key) != '\0') {
        ++hash_table[static_cast<int>(*(hash_key++))];
    }

    hash_key = str;
    while (*hash_key != '\0') {
        if (hash_table[static_cast<int>(*(hash_key++))] == 1) {
            return str - hash_key;
        }
    }

    return -1;
}

int main() {


    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>


int main() {

    std::ifstream in_file("./README.md");
    std::vector<std::string> input;
    std::map<std::string, std::set<decltype(input.size())>> str_line;
    decltype(input.size()) line_no{ 0 };

    for (std::string line; std::getline(in_file, line); ++line_no) {
        input.push_back(line);
        std::istringstream line_stream(line);
        for (std::string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(),
                                std::back_inserter(word), ispunct);
            str_line[word].insert(line_no);
        }
    }

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;

        auto found = str_line.find(s);
        if (found != str_line.end()) {
            std::cout << s << " occurs " << found->second.size()
                      << (found->second.size() > 1 ? " times" : " time")
                      << '\n';
            for (auto i : found->second) {
                std::cout << "\t(line " << i + 1 << ")" << input.at(i) << '\n';
            }
        }
        else {
            std::cout << s << " occurs 0 time" << '\n';
        }
    }

    return 0;
}



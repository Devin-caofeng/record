#include "../need.h"

class Families {
public:
    using Child    = std::pair<std::string, std::string>;
    using Childern = std::vector<Child>;
    using Data     = std::map<std::string, Childern>;

    void Add(const std::string &last_name,
             const std::string &first_name,
             const std::string &birthday) {
        auto child = make_pair(first_name, birthday);
        data_[last_name].push_back(child);
    }

    void Print() const {
        for (const auto &pair : data_) {
            std::cout << pair.first << ":\n";
            for (const auto &child : pair.second) {
                std::cout << child.first << " " << child.second << '\n';
            }
            std::cout << '\n';
        }
    }

private:
    Data data_;
};


int main() {


    return 0;
}

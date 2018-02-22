#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using std::string;

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<string>::size_type;

    TextQuery(std::ifstream &);
    QueryResult Query(const string &) const;

private:
    std::shared_ptr<std::vector<string>> file_;
    std::map<string, std::shared_ptr<std::set<line_no>>> word_line_;
};

class QueryResult {
friend std::ostream &Print(std::ostream &, const QueryResult &);
using line_no = std::vector<string>::size_type;

public:
    QueryResult(string s, std::shared_ptr<std::set<line_no>> ptr,
                std::shared_ptr<std::vector<string>> file)
        : sought_(s), lines_(ptr), file_(file) { }

private:
    string sought_;
    std::shared_ptr<std::set<line_no>> lines_;
    std::shared_ptr<std::vector<string>> file_;
};


TextQuery::TextQuery(std::ifstream &ifs)
    : file_(std::make_shared<std::vector<string>>()) {
    string text;
    while (std::getline(ifs, text)) {
        file_->push_back(text);
        int n = file_->size() - 1;
        std::istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = word_line_[word];
            if (!lines) {
                lines.reset(std::make_shared<std::set<line_no>>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::Query(const string &sought) const {
    static auto no_data = std::make_shared<std::set<line_no>>();
    auto loc = word_line_.find(sought);
    if (loc == word_line_.end()) {
        return QueryResult(sought, no_data, file_);
    }
    else {
        return QueryResult(sought, loc->second, file_);
    }
}

std::ostream &Print(std::ostream &os, const QueryResult &res) {
    os << res.sought_ << " occurs " << res.lines_->size() << " "
//       << make_plural(res.lines_->size(), "time", "s") << '\n';
       << "time" << '\n';
    for (auto num : *res.lines_) {
        os << "\t(line " << num + 1 << ") "
           << *(res.file_->begin() + num) << '\n';
    }

    return os;
}


int main() {

    std::ifstream ifs{ "./ex12_6.cpp" };
    TextQuery tq{ ifs };

    Print(std::cout, tq.Query("main"));

    return 0;
}



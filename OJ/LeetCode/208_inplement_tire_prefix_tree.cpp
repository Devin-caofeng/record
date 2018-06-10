#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Tire {
public:
    Tire() : root_(new TrieNode()) { }

    void insert(string word) {
        TrieNode* p = root_.get();
        for (const char ch : word) {
            if (!p->childern[ch - 'a']) {
                p->childern[ch - 'a'] = new TrieNode();
            }
            p = p->childern[ch - 'a'];
        }
        p->is_word = true;
    }

    bool search(string word) {
        const TrieNode* p = find(word);
        return p && p->is_word;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct TrieNode {
        TrieNode() : is_word(false), childern(26, nullptr) { }

        ~TrieNode() {
            for (auto &child : childern) {
                if (child) delete child;
            }
        }

        bool is_word;
        vector<TrieNode*> childern;
    };

    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_.get();
        for (const char ch : prefix) {
            p = p->childern[ch - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }

    std::unique_ptr<TrieNode> root_;
};

int main() {
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "tree_node.hpp"
using namespace std;

class Codec {
public:
    string serialize(TreeNode *root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode *deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else {
            out << "# ";
        }
    }

    TreeNode *deserialize(istringstream &in) {
        string s;
        in >> s;
        if (s == "#") return NULL;

        TreeNode *root = new TreeNode(stoi(s));
        root->left = deserialize(in);
        root->right = deserialize(in);

        return root;
    }
};

int main() {
    return 0;
}

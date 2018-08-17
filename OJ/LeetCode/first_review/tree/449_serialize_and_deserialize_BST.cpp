#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    string serialize(TreeNode* root) {
        ostringstream os;
        doSerialize(root, os);
        return os.str();
    }

    TreeNode* deserialize(string data) {
        istringstream is(data);
        return doDeserialize(is);
    }

private:
    void doSerialize(TreeNode* root, ostringstream& os) {
        if (!root) {
            os << "# ";
        }
        else {
            os << root->val << " ";
            doSerialize(root->left, os);
            doSerialize(root->right, os);
        }
    }

    TreeNode* doDeserialize(istringstream& is) {
        string val;
        is >> val;
        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = doDeserialize(is);
        node->right = doDeserialize(is);
        return node;
    }
};

int main() {
    return 0;
}

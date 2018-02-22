#include <iostream>
#include <string>

using std::string;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    char *Serialize(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        string str;
        DoSerialize(root, str);
        char *ret = new char[str.size() + 1];
        size_t i;
        for (i = 0; i < str.size(); ++i) {
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }

    void DoSerialize(TreeNode *root, string &str) {
        if (root == NULL) {
            str += '#';
            return;
        }

        string r = std::to_string(root->val);
        str += r;
        str += ',';
        DoSerialize(root->left, str);
        DoSerialize(root->right, str);
    }

    TreeNode *Deserialize(char *str) {
        if (str == NULL) {
            return NULL;
        }
        TreeNode *ret = DoDeserialize(&str);

        return ret;
    }

    TreeNode *DoDeserialize(char **str) {
        if (**str == '#') {
            ++(*str);
            return NULL;
        }
        int num = 0;
        while (**str != '\0' && **str != ',') {
            num = num * 10 + ((**str) - '0');
            ++(*str);
        }

        TreeNode *root = new TreeNode(num);
        if (**str == '\0') {
            return root;
        }
        else {
            ++(*str);
        }
        root->left = DoDeserialize(str);
        root->right = DoDeserialize(str);

        return root;
    }
};

int main() {



    return 0;
}

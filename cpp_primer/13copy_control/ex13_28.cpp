#include <iostream>
#include <string>

class TreeNode {
public:
    TreeNode()
        : value_(std::string()),
          count_(new int(1)),
          left_ (nullptr),
          right_(nullptr) { }

    TreeNode(const TreeNode &tn)
        : value_(tn.value_),
          count_(tn.count_),
          left_ (tn.left_),
          right_(tn.right_) { ++*count_; }

    TreeNode &operator=(const TreeNode &tn) {
        ++*tn.count_;
        if (--*count_ == 0) {
            delete count_;
            delete left_;
            delete right_;
        }

        value_ = tn.value_;
        count_ = tn.count_;
        left_  = tn.left_;
        right_ = tn.right_;
        return *this;
    }

    ~TreeNode() {
        delete count_;
        delete left_;
        delete right_;
    }

private:
    std::string value_;
    int         *count_;
    TreeNode    *left_;
    TreeNode    *right_;
};

class BinStrTree {
public:
    BinStrTree() : root_(new TreeNode()) { }

    BinStrTree(const BinStrTree &bst) : root_(new TreeNode(*bst.root_)) { }

    BinStrTree &operator=(const BinStrTree &bst) {
        TreeNode *new_root = new TreeNode(*bst.root_);
        delete root_;
        root_ = new_root;
        return *this;
    }

    ~BinStrTree() { delete root_; }

private:
    TreeNode *root_;
};

int main() {



    return 0;
}

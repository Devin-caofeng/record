#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BST {
private:
    enum { BLACK = 0, RED };

    struct Node {
        int  value;
        bool color;
        Node *left_tree, *right_tree, *parent;

        Node() : value(0), color(RED), left_tree(nullptr), right_tree(nullptr),
                 parent(nullptr) { }

        Node *Grandparent() {
            if (parent == nullptr) return nullptr;
            else return parent->parent;
        }

        Node *Uncle() {
            if (Grandparent() == nullptr) return nullptr;

            if (parent == Grandparent()->right_tree) {
                return Grandparent()->left_tree;
            }
            else {
                return Grandparent()->right_tree;
            }
        }

        Node *Sibling() {
            if (parent->left_tree == this) return parent->right_tree;
            else return parent->left_tree;
        }

        Node *RotateRight(Node *ptr) {
            Node *gptr = ptr->Grandparent();
            Node *fptr = ptr->parent;
            Node *y = ptr->right_tree;

            fptr->left_tree = y;
            if (y != NIL_) y->parent = fptr;
            ptr->right_tree = fptr;

            return y;
        }
    };

public:
    BST() : root_(nullptr), NIL_(new Node()) { NIL_->color = BLACK; }

    ~BST() { delete NIL_; }

    void Inorder() {
        if (root_ == nullptr) return;
        Inorder(root_);
        cout << endl;
    }

    void Insert(int x) {
        if (root_ == nullptr) {
            root_ = new Node();
            root_->color = BLACK;
            root_->left_tree = root_->right_tree = NIL_;
            root_->value = x;
        }
        else {
            Insert(root_, x);
        }
    }

    bool DeleteValue(int data) {
        return DeleteChild(root_, data);
    }

private:
    Node *root_;
    Node *NIL_;
};


int main() {



    return 0;
}

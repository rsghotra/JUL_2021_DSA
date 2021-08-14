#include "bst.h"
#include<iostream>
#include<stack>
using namespace std;

BST::BST() {
    this->root = 0;
}
TreeNode* BST::Insert(int key) {
    if(this->root == 0) {
        this->root = Insert(this->root, key);
        return this->root;
    }
    return Insert(this->root, key);
}

TreeNode* BST::Insert(TreeNode* ptr, int key) {
    //insertion will always happen at the leaf.
    if(ptr == 0) {
        ptr = new TreeNode(key);
        return ptr;
    }
    if(key < ptr->data) {
        ptr->left = Insert(ptr->left, key);
    } else if(key > ptr->data) {
        ptr->right = Insert(ptr->right, key);
    }
    //duplicate value found, hence no insertion as BST do not allow duplicates.
    return ptr;
}

void BST::InOrder() {
    cout << "Printing BST Inorder: " << endl;
    InOrder(this->root);
}

void BST::InOrder(TreeNode* t) {
    stack<TreeNode*> stk;
    while(t != 0 || stk.empty() == false) {
        if(t != 0) {
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();stk.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

int BST::Height(TreeNode* ptr) {
    int x,y;
    if(ptr == 0) return 0;
    if(ptr->left == 0 && ptr->right == 0) return 0;
    else {
        x = Height(ptr->left);
        y = Height(ptr->right);
        if(x > y) return x + 1;
        else return y + 1;
    }
}

void BST::Delete(int key) {
    cout << "==>Deleting key: " << key << endl;
    Delete(this->root, key);
}

TreeNode* BST::Inorder_Predecessor(TreeNode* ptr) {
    while(ptr && ptr->right) {
        ptr = ptr->right;
    }
    return ptr;
}

TreeNode* BST::Inorder_Successor(TreeNode* ptr) {
    while(ptr && ptr->left) {
        ptr = ptr->left;
    }
    return ptr;
}

TreeNode* BST::Delete(TreeNode* ptr, int key) {
    if(ptr == 0) return 0;
    if(ptr->data == key && ptr->left == 0 && ptr->right == 0) {
        if(ptr == this->root) {
            root = 0;
        }
        delete ptr;
        ptr = 0;
        return nullptr;
    } else {
        //post order format
        if(key < ptr->data) {
            ptr->left = Delete(ptr->left, key);
        } else if(key > ptr->data) {
            ptr->right = Delete(ptr->right, key);
        } else {
            if(Height(ptr->left) > Height(ptr->right)) {
                TreeNode* qtr = Inorder_Predecessor(ptr->left);
                ptr->data = qtr->data;
                ptr->left = Delete(ptr->left, qtr->data);
            } else {
                TreeNode* qtr = Inorder_Successor(ptr->right);
                ptr->data = qtr->data;
                ptr->right = Delete(ptr->right, qtr->data);
            }
        }
    }
}
void BST::Height() {
    cout << "Height of the tree: " << Height(this->root) << endl;
}
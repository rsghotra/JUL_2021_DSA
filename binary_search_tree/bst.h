#ifndef BST_H
#define BST_H
#include<iostream>
#include<vector>

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int data;
    TreeNode(int data) {
        this->left = 0;
        this->right = 0;
        this->data = data;
    }
};

class BST {
private:
    TreeNode* root;
    int Height(TreeNode*);
    void InOrder(TreeNode*);
    TreeNode* Insert(TreeNode*, int);
    TreeNode* Delete(TreeNode*, int);
    TreeNode* Inorder_Predecessor(TreeNode*);
    TreeNode* Inorder_Successor(TreeNode*);
public:
    BST();
    void Height();
    void InOrder();
    TreeNode* Insert(int);
    void Delete(int key);
    void GenerateBSTFromPreOrder(std::vector<int>&);
};

#endif
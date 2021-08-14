#ifndef BT_H
#define BT_H
#include<string>

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int data;
    TreeNode(int data) {
        this->data = data;
        this->left = this->right = 0;
    }
};

class BinaryTree {
private:
    TreeNode* root;
    void PostOrder(TreeNode*);
    void PreOrder(TreeNode*);
    void InOrder(TreeNode*);
    int  CountNodes(TreeNode*);
    int  Sum(TreeNode*);
    int  Height(TreeNode*);
public:
    BinaryTree();
    void CreateTree();
    void CountNodes();
    void Sum();
    int  Deg2Nodes();
    int  Deg1Nodes();
    void  Height();
    void LevelOrder();
    void PreOrder();
    void InOrder();
    void PostOrder();
    int  NumberOfUniqueTreesGivenNodes(int);
};

#endif
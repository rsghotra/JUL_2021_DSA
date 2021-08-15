#ifndef AVL_H
#define AVL_H
/*
Insertion:
LL Rotation: +2,+1
RR Rotation: -2,-1
LR Rotation: +2,-1
RL Rotation: -2,+1

Deletion:
L-1,L0,L1
R-1,R0,R1
*/
class TreeNode {
    public:
        TreeNode* left;
        TreeNode* right;
        int height;
        int data;
        TreeNode(int data) {
            this->left = this->right = 0;
            this->height = 0;
            this->data = data;
        }
};
class AVL {
    private:
        TreeNode* root;
        TreeNode* Insert(TreeNode*, int);
        TreeNode* InorderPred(TreeNode*);
        TreeNode* InorderSucc(TreeNode*);
        TreeNode* Delete(TreeNode*, int key);
        void      InOrder(TreeNode*);
    public:
        AVL();
        int BalanceFactor(TreeNode*);
        int NodeHeight(TreeNode*);
        TreeNode* Insert(int);
        void Delete(int);
        int Height(TreeNode*);
        void InOrder();
        TreeNode* LLRotation(TreeNode*);
        TreeNode* RRRotation(TreeNode*);
        TreeNode* LRRotation(TreeNode*);
        TreeNode* RLRotation(TreeNode*);
};
#endif

#ifndef BT_H
#define BT_H
#include<string>
#include<vector>
#include<deque>
using namespace std;
class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    int data;
    TreeNode(int data) {
        this->data = data;
        this->left = this->right = 0;
        this->next = 0;
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
    TreeNode* GenerateBTFromPreOrderAndInOrder(vector<int>&, vector<int>&, int, int);
    vector<vector<int>> LevelOrderPattern(TreeNode*);
    deque<vector<int>> ReverseLevelOrderPattern(TreeNode*);
    vector<vector<int>> ZigZagTraversal(TreeNode*);
    vector<double> LevelAverage(TreeNode*);
    int MinDepth(TreeNode*);
    TreeNode* LevelOrderSuccessor(TreeNode*);
    bool HasPath(TreeNode*, int);
    void AllPathsForSum(TreeNode*, int, vector<int>&, vector<vector<int>>&);
    void AllPaths(TreeNode*, vector<int>&, vector<vector<int>>&);
    int SumOfPathNumbers(TreeNode*, int pathSum);
    bool FindIfSequencePathExists(TreeNode*, vector<int>&, unsigned int);
    int CountNonRootedPathsForSum(TreeNode*, vector<int>&, int);
    int Diameter(TreeNode*);
public:
    BinaryTree();
    void CreateTree();
    void CountNodes();
    void Sum();
    void Deg2Nodes();
    void Deg1Nodes();
    void Height();
    void LevelOrder();
    void LevelOrderPattern();
    void ZigZagTraversal();
    void ReverseLevelOrderPattern();
    void PreOrder();
    void InOrder();
    void PostOrder();
    int  NumberOfUniqueTreesGivenNodes(int);
    void GenerateBTFromPreOrderAndInOrder(vector<int>&, vector<int>&);
    int  SearchInOrder(vector<int>& inorder, int start, int end, int key);
    void LevelAverage();
    void MinDepth();
    void LevelOrderSuccessor(int);
    void ConnectLevelOrderSiblings();
    void ConnectLevelOrderSiblingsToNextLevel();
    void RightView();
    void HasPath(); //T = o(n); S = o(n)
    void AllPathsForSum();
    void AllPaths();
    void SumOfPathNumbers();
    void FindIfSequencePathExists();
    void CountNonRootedPathsForSum();
    void Diameter();
};

#endif
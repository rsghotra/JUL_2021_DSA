#include "bt.h"
#define COUNT 10
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

BinaryTree::BinaryTree() {
    this->root = 0;
}

void BinaryTree::CreateTree() {
    queue<TreeNode*> queue;
    int x;
    TreeNode* ptr = 0;
    cout << "==>Enter root value: " << endl;
    cin >> x;
    this->root = new TreeNode(x);
    //see queue with root;
    queue.emplace(this->root);
    while(!queue.empty()) {
        ptr = queue.front();
        queue.pop();
        cout << "Enter left child of " << ptr->data << " node: ";
        cin >> x;
        if(x != -1) {
            ptr->left = new TreeNode(x);
            queue.push(ptr->left);
        }
        cout << "Enter right child of " << ptr->data << " node: ";
        cin >> x;
        if(x != -1) {
            ptr->right = new TreeNode(x);
            queue.push(ptr->right);
        }
    }
}

void BinaryTree::LevelOrder() {
    cout << "==>Printing Level Order traversal." << endl;
    if(this->root != 0) {
        queue<TreeNode*> queue;
        TreeNode* ptr = 0;
        queue.push(this->root);

        while(!queue.empty()) {
            ptr = queue.front();
            queue.pop();
            cout << ptr->data << " ";
            if(ptr->left) queue.push(ptr->left);
            if(ptr->right) queue.push(ptr->right);
        }
    }
}

void BinaryTree::PreOrder() {
    cout << "\n==>Preorder sequence:" << endl;
    PreOrder(this->root);
}

void BinaryTree::PreOrder(TreeNode* t) {
    stack<TreeNode*> stk;
    while(t != 0 || stk.empty() == false) {
        if(t!=0) {
            cout << t->data << " ";
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();
            stk.pop();
            t = t->right;
        }
    }
}

void BinaryTree::InOrder() {
    cout << "\n==>Inorder sequence: " << endl;
    InOrder(this->root);
}

void BinaryTree::InOrder(TreeNode* t) {
    stack<TreeNode*> stk;
    while(t != 0 || stk.empty() == false) {
        if(t!=0) {
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();
            stk.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

void BinaryTree::PostOrder() {
    cout << "\n==>Postorder sequence: " << endl;
    PostOrder(this->root);
}

void BinaryTree::PostOrder(TreeNode* t) {
    stack<long int> stk;
    long int temp;
    while(t != 0 || stk.empty() == false) {
        if(t!=0) {
            stk.push((long int)(t));
            t = t->left;
        } else {
            temp= stk.top();
            stk.pop();
            if(temp > 0) {
                stk.push(-temp);
                t = ((TreeNode*)(temp))->right;
            } else {
                cout << ((TreeNode*)(-1 * temp))->data << " ";
                t = 0;
            }
        }
    }
}

void BinaryTree::CountNodes() {
    cout << "\n==>Number of nodes: " << CountNodes(this->root) << " in the tree." << endl;
}

int BinaryTree::CountNodes(TreeNode* ptr) {
    int x, y;
    if(ptr != 0) {
        x = CountNodes(ptr->left);
        y = CountNodes(ptr->right);
        return x+y+1;
    }   
    return 0;
}

void BinaryTree::Sum() {
    cout << "==>Sum of nodes: " << Sum(this->root) << " in the tree." << endl;
}

int BinaryTree::Sum(TreeNode* ptr) {
    int x, y;
    if(ptr != 0) {
        x = Sum(ptr->left);
        y = Sum(ptr->right);
        return x+y+ptr->data;
    }   
    return 0;
}

void BinaryTree::Height() {
    cout << "==>Height of tree: " << Height(this->root) << "." << endl;
}

int BinaryTree::Height(TreeNode* ptr) {
    int x, y;
    if(ptr == 0) return 0;
    if(ptr->left == 0 && ptr->right == 0) return 0;
    if(ptr!= 0) {
        x = Height(ptr->left);
        y = Height(ptr->right);
        if(x>y) return x+1;
        else return y+1;
    }
}

void BinaryTree::GenerateBTFromPreOrderAndInOrder(vector<int>& preorder, vector<int>& inorder) {
    this->root = GenerateBTFromPreOrderAndInOrder(preorder, inorder, 0, inorder.size() - 1);
}

int BinaryTree::SearchInOrder(vector<int>& inorder, int start, int end, int key) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == key) return i;
    }
    return -1;
}

TreeNode* BinaryTree::GenerateBTFromPreOrderAndInOrder(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
    static int preIndex = 0;
    if(inStart > inEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[preIndex]);
    preIndex++;
    if(inStart == inEnd) return root;
    int splitIndex = SearchInOrder(inorder, inStart, inEnd, root->data);
    root->left = GenerateBTFromPreOrderAndInOrder(preorder, inorder, inStart, splitIndex-1);
    root->right = GenerateBTFromPreOrderAndInOrder(preorder, inorder, splitIndex+1, inEnd);
    return root;
}
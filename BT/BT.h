#ifndef BT_H
#define BT_H
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        this->data = x;
        this->left = 0;
        this->right = 0;
    }
};

class BT {
    public:
        TreeNode* root = 0;
        std::queue<TreeNode*> q;
        BT(){
            std::cout << "Tree created." << std::endl;
        }
        void create();
        void InOrder_R(TreeNode* ptr);
        void PreOrder_R(TreeNode* ptr);
        void PostOrder_R(TreeNode* ptr);
        void InOrder_I(TreeNode* ptr);
        void PreOrder_I(TreeNode* ptr);
        void PostOrder_I(TreeNode* ptr);
        void LevelOrder();
        TreeNode* GenerateTreeFromInorderPreorder(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd);
        int SearchInorder(vector<int>& inorder, int start, int end, int val);
};

void BT::create() {
    int x;
    cout << "Enter root's value: " << endl;
    cin >> x;
    TreeNode* ptr = 0;
    this->root = new TreeNode(x);
    q.push(root);

    while(!q.empty()) {
        ptr = q.front();
        q.pop();
        cout << "Enter left child of " << ptr->data << endl;
        cin >> x;
        if(x != -1) {
            ptr->left = new TreeNode(x);
            q.push(ptr->left);
        }
        cout << "Enter right child of " << ptr->data << endl;
        cin >> x;
        if(x != -1) {
            ptr->right = new TreeNode(x);
            q.push(ptr->right);
        }
    }
}

void BT::InOrder_R(TreeNode* ptr) {
    if(ptr) {
        InOrder_R(ptr->left);
        cout << ptr->data << " ";
        InOrder_R(ptr->right);
    }
}

void BT::PreOrder_R(TreeNode* ptr) {
    if(ptr) {
        cout << ptr->data << " ";
        PreOrder_R(ptr->left);
        PreOrder_R(ptr->right);
    }
}

void BT::PostOrder_R(TreeNode* ptr) {
    if(ptr) {
        PostOrder_R(ptr->left);
        PostOrder_R(ptr->right);
        cout << ptr->data << " ";
    }
}

void BT::LevelOrder() {
    queue<TreeNode*> q;
    TreeNode* temp = root;
    if(temp == 0) return;
    cout << temp->data << " ";
    q.push(temp);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->left) {
            cout << temp->left->data << " ";
            q.push(temp->left);
        }
        if(temp->right) {
            cout << temp->right->data << " ";
            q.push(temp->right);
        }
    }
}

void BT::PreOrder_I(TreeNode* t) {
    stack<TreeNode*> stk;
    while( t!= 0 || stk.empty() == false) {
        if(t != 0 ) {
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

void BT::InOrder_I(TreeNode* t) {
    stack<TreeNode*> stk;
    while(t != 0 || stk.empty() == false) {
        if(t != 0) {
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top(); stk.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

void BT::PostOrder_I(TreeNode* t) {
    stack<long int> stk;
    long int temp;
    while(t != 0 || stk.empty() == false) {
        if(t != 0) {
            stk.push((long int)t);
            t = t->left;
        } else {
            temp = stk.top(); stk.pop();
            if(temp > 0) {
                stk.push(-temp);
                t = ((TreeNode*)temp)->right;
            } else {
                cout << ((TreeNode*)(-1 * temp))->data << " ";
                t = 0;
            }
        }
    }
}

int BT::SearchInorder(vector<int>& inorder, int start, int end, int data) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == data) {
            return i;
        }
    }
    return -1;
}


TreeNode* BT::GenerateTreeFromInorderPreorder(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd) {
    static int preIndex = 0;

    //first exit condition
    if(inorderStart > inorderEnd) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[preIndex]);
    preIndex++;
    if(inorderStart == inorderEnd) {
        return node;
    }

    int splitIndex = SearchInorder(inorder, inorderStart, inorderEnd, node->data);
    node->left = GenerateTreeFromInorderPreorder(preorder, inorder, inorderStart, splitIndex - 1);
    node->right = GenerateTreeFromInorderPreorder(preorder, inorder, splitIndex+1, inorderEnd);
    return node;
}


#endif
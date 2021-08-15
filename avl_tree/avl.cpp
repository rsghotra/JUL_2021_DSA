#include "avl.h"
#include<iostream>
#include<stack>
AVL::AVL() {
    this->root = 0;
}

TreeNode* AVL::InorderPred(TreeNode* ptr) {
    while(ptr && ptr->right) {
        ptr = ptr->right;
    }
    return ptr;
}

TreeNode* AVL::InorderSucc(TreeNode* ptr) {
    while(ptr && ptr->left) {
        ptr = ptr->left;
    }
    return ptr;
}

TreeNode* AVL::Insert(int key) {
    if(this->root == 0) {
        this->root = Insert(this->root, key);
        return this->root;
    }
    return Insert(this->root, key);
}

TreeNode* AVL::Insert(TreeNode* ptr, int key) {
    if(ptr == 0) {
        ptr = new TreeNode(key);
        if(this->root == 0) {
            this->root = ptr;
        }
        return ptr;
    }
    if(key < ptr->data) {
        ptr->left = Insert(ptr->left, key);
    } else if(key > ptr->data) {
        ptr->right = Insert(ptr->right, key);
    }
    //update height of each node while returning
    ptr->height = Height(ptr);
    
    if(BalanceFactor(ptr) == 2 && BalanceFactor(ptr->left) == 1) {
        return LLRotation(ptr);
    } else if(BalanceFactor(ptr) == -2 && BalanceFactor(ptr->right) == -1) {
        return RRRotation(ptr);
    } else if(BalanceFactor(ptr) == 2 && BalanceFactor(ptr->left) == -1) {
        return LRRotation(ptr);
    } else if(BalanceFactor(ptr) == -2 && BalanceFactor(ptr->right) == 1) {
        return RLRotation(ptr);
    }
    return ptr;
}

int AVL::BalanceFactor(TreeNode* ptr) {
    int hl, hr = 0;
    if(ptr->left) hl = ptr->left->height;
    if(ptr->right) hr = ptr->right->height;
    return hl - hr;
}

TreeNode* AVL::LLRotation(TreeNode* p) {
    TreeNode* pl = p->left;
    TreeNode* plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = Height(p);
    pl->height = Height(pl);

    if(root == p) {
        root = pl;
    }

    return pl;
}

TreeNode* AVL::RRRotation(TreeNode* p) {
    TreeNode* pr = p->right;
    TreeNode* prl = pr->left;
    
    pr->left = p;
    p->right = prl;

    p->height = Height(p);
    pr->height = Height(pr);
    
    if(root == p) {
        root = pr;
    }
    return pr;
}

TreeNode* AVL::LRRotation(TreeNode* p) {
    TreeNode* pl = p->left;
    TreeNode* plr = pl->right;

    //jisko root mein bhejna hai pehle uske child niptao;
    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    p->height = Height(p);
    pl->height = Height(pl);
    plr->height = Height(plr);
    
    if(root == p) {
        root = plr;
    }
    
    return plr;
}

TreeNode* AVL::RLRotation(TreeNode* p) {
    TreeNode* pr = p->right;
    TreeNode* prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;

    prl->right = pr;
    prl->left = p;

    p->height = Height(p);
    pr->height = Height(pr);
    prl->height = Height(prl);

    if(this->root == p) {
        this->root = prl;
    }
    return prl;
}

void AVL::Delete(int key) {
    std::cout << "==>Deleting key " << key << std::endl;
    Delete(this->root, key);
}

int AVL::Height(TreeNode* ptr) {
    int x, y;
    if(ptr == 0) return 0;
    if(ptr->left == 0 && ptr->right == 0) return 0;
    else {
        x = Height(ptr->left);
        y = Height(ptr->right);
        if(x > y) return x+1;
        else return y+1;
    }
}

TreeNode* AVL::Delete(TreeNode* ptr, int key) {
    if(ptr == 0) return nullptr;
    if(ptr->data == key && ptr->left == 0 && ptr->right == 0) {
        if(ptr == this->root) {
            this->root = 0;
        }
        delete ptr;
        ptr = 0;
        return nullptr;
    } else {
        if(key < ptr->data) {
            ptr->left = Delete(ptr->left, key);
        } else if(key > ptr->data) {
            ptr->right = Delete(ptr->right, key);
        } else {
            TreeNode* qtr = 0;
            if(Height(ptr->left) > Height(ptr->right)) {
                qtr = InorderPred(ptr->left);
                ptr->data = qtr->data;
                ptr->left = Delete(ptr->left, qtr->data);
            } else {
                qtr = InorderSucc(ptr->right);
                ptr->data = qtr->data;
                ptr->right = Delete(ptr->right, qtr->data);
            }
        }
    }
    ptr->height = Height(ptr);

    //BalanceFactorAndRotation
    if(BalanceFactor(ptr) == 2 && BalanceFactor(ptr->left) == 1) { //L1 Rotation
        return LLRotation(ptr);
    } else if(BalanceFactor(ptr) == -2 && BalanceFactor(ptr->right) == -1) { //R-1 Rotation
        return RRRotation(ptr);
    } else if(BalanceFactor(ptr) == 2 && BalanceFactor(ptr->right) == -1) { //L-1
        return LRRotation(ptr);
    } else if(BalanceFactor(ptr) == -2 && BalanceFactor(ptr->left) == 1) {//R1
        return RLRotation(ptr);
    } else if(BalanceFactor(ptr) == 2 && BalanceFactor(ptr->left) == 0) { //L0 Rotation
        return LLRotation(ptr);
    } else if(BalanceFactor(ptr) == -2 && BalanceFactor(ptr->right) == 0) {
        return RRRotation(ptr);
    }
    return ptr;
}

void AVL::InOrder() {
    std::cout << "Printing BST Inorder: " << std::endl;
    InOrder(this->root);
}

void AVL::InOrder(TreeNode* t) {
    std::stack<TreeNode*> stk;
    while(t != 0 || stk.empty() == false) {
        if(t != 0) {
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();stk.pop();
            std::cout << t->data << " ";
            t = t->right;
        }
    }
}
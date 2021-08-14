#include "bst.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    BST* bst = new BST();
    vector<int> preorder{30,20,10,15,25,40,50,45};
    bst->Insert(20);
    bst->Insert(10);
    bst->Insert(25);
    bst->Insert(35);
    bst->Insert(11);
    bst->InOrder();
    bst->Height();
    bst->Delete(10);
    bst->Delete(20);
    bst->InOrder();
    bst->GenerateBSTFromPreOrder(preorder);
    bst->InOrder();
}
#include "bt.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    cout << "Compiled and printed successfully" << endl;
    vector<int> preorder{4,7,9,6,3,2,5,8,1};
    vector<int> inorder{7,6,9,3,4,5,8,2,1};
    BinaryTree* bt = new BinaryTree();
    bt->CreateTree();
    bt->LevelOrder();
    bt->PreOrder();
    bt->InOrder();
    bt->PostOrder();
    bt->CountNodes();
    bt->Sum();
    bt->Height();
    bt->GenerateBTFromPreOrderAndInOrder(preorder, inorder);
    cout << "New Tree: " << endl;
    bt->LevelOrderPattern();
    return 0;
}
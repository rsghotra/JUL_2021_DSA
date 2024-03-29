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
    bt->HasPath();
    bt->AllPathsForSum();
    bt->AllPaths();
    bt->SumOfPathNumbers();
    bt->FindIfSequencePathExists();
    bt->CountNonRootedPathsForSum();
    bt->GenerateBTFromPreOrderAndInOrder(preorder, inorder);
    bt->LevelOrderPattern();
    bt->ReverseLevelOrderPattern();
    bt->ZigZagTraversal();
    bt->LevelAverage();
    bt->MinDepth();
    bt->LevelOrderSuccessor(1);
    bt->ConnectLevelOrderSiblings();
    bt->ConnectLevelOrderSiblingsToNextLevel();
    bt->RightView();
    bt->Diameter();
    return 0;
}
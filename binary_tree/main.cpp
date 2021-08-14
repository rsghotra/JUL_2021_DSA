#include "bt.h"
#include<iostream>
using namespace std;

int main() {
    cout << "Compiled and printed successfully" << endl;
    BinaryTree* bt = new BinaryTree();
    bt->CreateTree();
    bt->LevelOrder();
    bt->PreOrder();
    bt->InOrder();
    bt->PostOrder();
    bt->CountNodes();
    bt->Sum();
    bt->Height();
    return 0;
}
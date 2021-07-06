#include <iostream>
#include "BT.h"
using namespace std;

int main() {
    BT* bt = new BT();
    bt->create();
    cout << "Inorder Iterative: " ;
    bt->InOrder_I(bt->root);
    cout << "Preorder Iterative: " ;
    bt->PreOrder_I(bt->root);
    cout << "Postorder Iterative: " ;
    bt->PostOrder_I(bt->root);
    cout << "LevelOrder Iterative: ";
    bt->LevelOrder();

    vector<int> preorder{4,7,9,6,3,2,5,8,1};
    vector<int> inorder{7,6,9,3,4,5,8,2,1};

    TreeNode* tree = bt->GenerateTreeFromInorderPreorder(preorder, inorder, 0, 8);

    bt->InOrder_I(tree);

    return 0;
}
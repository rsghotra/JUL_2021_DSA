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
    return 0;
}
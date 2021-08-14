#include "bst.h"
#include<iostream>
using namespace std;

int main() {
    BST* bst = new BST();
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
}
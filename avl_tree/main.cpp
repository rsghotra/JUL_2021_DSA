#include "avl.h"
#include<iostream>
using namespace std;

int main() {
    AVL tree;
 
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.Insert(A[i]);
    }
    tree.InOrder();
    cout << endl;   
}
#include<iostream>
using namespace std;
/*
 - Inserting one element in Heap = o(logn)
 - Inserting n elements in Heap = o(nlogn)
 - 
*/

void Swap(int A[], int i, int j) {
     int temp = A[i];
     A[i] = A[j];
     A[j] = temp;
}

void Print(int A[], int size) {
    for(int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Insert(int A[], int size, int indexToInsert) {
    int element = A[indexToInsert];
    int i = indexToInsert;
    while(i > 0 && element > A[(i-1)/2]) {
        A[i] = A[(i-1)/2];
        i = (i-1)/2;
    }
    A[i] = element;
}

int Delete(int A[], int lastIndex) {
    int val = A[0];
    A[0] = A[lastIndex];
    int i = 0;
    int j = 2*i+1;
    while(j < lastIndex-1) {
        if(A[j+1] > A[j]) {
            j = j+1;
        }
        if(A[j] > A[i]) {
            Swap(A, i, j);
            i = j;
            j = 2*i + 1;
        }
    }
    //Heap Sort;
    A[lastIndex] = val; //heap sort
    return val;
}


int main () {
    int size = 7;
    int A[7] = {10,20,30,25,5,40,35};//first element is considered part of the heap
    for(int i = 1; i < 7; i++) {
        Insert(A, 7, i);
    }
    cout << "Printing" << endl;
    Print(A, 7);
    for(int j = size-1;j >= 0;j--) {
        Delete(A, j);
    }
    Print(A, size);
}
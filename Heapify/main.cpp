#include<iostream>
using namespace std;
#define SIZE 10

void Swap(int A[], int i, int j) {
     int temp = A[i];
     A[i] = A[j];
     A[j] = temp;
}

void Print(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Heapify(int A[], int size) {
    int i = size-1;
    int j;
    for(i; i >= 0; i--) {
        j = 2*i+1;
        if(j+1 < size) {
            if(A[j+1] > A[j]) {
                j = j+1;
            }
            if(A[j] > A[i]) {
                swap(A[i], A[j]);
            } else {
                break;
            }
        }
    }
}


int main() {
    int A[]{5,10,30,20,35,40,15};
    Heapify(A, 7);
    Print(A, 7);
    int B[]{5,10, 30,20};
    Heapify(B, 4);
    Print(B, 4);
    return 0;
}
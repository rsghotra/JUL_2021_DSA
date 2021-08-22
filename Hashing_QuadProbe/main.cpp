#include<iostream>
#define SIZE 10
using namespace std;

void Print(int HT[]) {
    for(int i=0;i<SIZE;i++) {
        cout << HT[i] << " ";
    }
}

int Hash(int key) {
    return key%SIZE;
}

int QuadraticProbe(int HT[], int key) {
    int idx = Hash(key);
    int i = 0;
    do {
        if(HT[(idx+i*i)%SIZE] == 0) {
            return ((idx+i*i)%SIZE);
        }
        i++;
    } while((idx + i*i)%SIZE != idx);
    return -1;
}

void Insert(int HT[], int key) {
    int idx = Hash(key);
    if(HT[idx] != 0) {
        idx = QuadraticProbe(HT, key);
    }
    if(idx == -1) {
        cout << "Could not insert " << key << " because Hash table is full" << endl;
        return;
    }
    HT[idx] = key;
}

int Search(int HT[], int key) {
    int idx = Hash(key);
    int i = 0;
    do {
        if(HT[(idx+i*i)%SIZE] == key) {
            return ((idx+i*i)%SIZE);
        }
        if(HT[(idx+i*i)%SIZE] == 0) {
            return -1;
        }
        i++;
    } while((idx+i*i)%SIZE != idx);
    return -1;
}

int main() {
    int A[]{26, 30, 45, 23, 25, 43, 74, 19, 29};
    int HT[SIZE] = {0};
    //insert elements to the hash table
    for(int i = 0; i < 9; i++) {
        Insert(HT, A[i]);
    }

    int idx = Search(HT, 45);
    cout << "Element found at idx= " << idx << endl;
    idx=Search(HT, 13);
    cout << "Element found at idx= " << idx << endl;
    Print(HT);
    return 0;
}
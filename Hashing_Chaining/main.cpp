#include<iostream>
#define SIZE 10
using namespace std;

struct Node {
    Node* next;
    int data;
};

int Hash(int key) {
    return key%SIZE;
}

int Search(Node** HT, int key) {
    int index = Hash(key);

    if(HT[index]  != 0) {
        Node* ptr = HT[index];
        while(ptr) {
            if(ptr->data == key) {
                return ptr->data;
            }
            ptr = ptr->next;
        }
    }
    return -1;
}

void Insert(Node** HT, int key) {
    int index = Hash(key);
    Node* temp = new Node();
    temp->data = key;
    temp->next = 0;
    //block is empty
    if(HT[index] == nullptr) {
        //spot is empty;
        HT[index] = temp;
    } else {
        Node* ptr = HT[index];
        Node* qtr = 0;
        //handling head insertion
        if(ptr->data > key) {
            temp->next = ptr;
            ptr = temp;
            HT[index] = temp;
        } else {
            while(ptr && ptr->data < key) {
                qtr = ptr;
                ptr = ptr->next;
            }
            temp->next = qtr->next;
            qtr->next = temp;
        }
    }
}

void Print(Node** HT) {
    Node* ptr = 0;
    if(HT != 0) {
        for(int i = 0; i < SIZE; i++) {
            ptr = HT[i];
            if(ptr == 0) cout << "XXXXX" << " ";
            while(ptr != 0) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
}

int main() {
    int A[9] = {16,12,25,39,6,122,68,75};
    Node** HT = new Node*[SIZE];
    for(int i = 0; i < SIZE; i++) {
        HT[i] = nullptr;
    }

    for(int i = 0; i < 9; i++) {
        Insert(HT, A[i]);
    }

    int index = Search(HT, 25);
	cout << "\nKey found: " << index << endl;
	index = Search(HT, 44);
	cout << "Key not found: "<< index << endl;
}
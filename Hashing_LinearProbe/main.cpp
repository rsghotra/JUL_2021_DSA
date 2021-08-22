#include<iostream>
#include<vector>
#define SIZE 10
using namespace std;

void Print(int HT[]) {
	for(int i = 0; i < SIZE; i++) {
		cout << HT[i] << " ";
	}
}

int Hash(int key) {
	return key%SIZE;
}

int LinearProbe(int HT[], int key) {
	int idx = Hash(key);
	int i = 0;
	do {
		if(HT[(idx+i)%SIZE] == 0) {
			return ((idx+i)%SIZE);
		}
		i++;
	} while((idx+i)%SIZE != idx);
	return -1;
}

void Insert(int HT[], int key) {
	int index = Hash(key);
	if(HT[index] != 0) {
		index = LinearProbe(HT, key);
	}
	if(index == -1) {
		cout << "HT is full, can't insert" << endl;
		return;
	}
	HT[index] = key;
}

int Search(int HT[], int key) {
	int idx = Hash(key);
	int i = 0;
	do {
		if(HT[(idx+i)%SIZE] == key) {
			return (idx+i)%SIZE;
		} else if(HT[(idx+i)%SIZE] == 0) {
			return -1; //first blank space means element won't be found.
		}
		i++;
	} while((idx+i)%SIZE != idx);
	return -1;
}

int main() {
	vector<int> input{26, 30, 45, 23, 25, 43, 74, 19, 29};
	
	//Hash Table
	int HT[SIZE] = {0};
	for(auto ele: input) {
		Insert(HT, ele);
	}
	Print(HT);
	int index = Search(HT, 25);
	cout << "\nKey found at index: " << index << endl;
	index = Search(HT, 44);
	cout << "Key found at index: "<< index << endl;
}


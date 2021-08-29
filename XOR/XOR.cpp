#include "XOR.h"
//Given an array of n−1 integers in the range from 1 to n, 
//find the one number that is missing from the array.
int XOR::FindMissingNumber(const vector<int>& arr) {
    //idea is first to find n --> find xor of 1 to n numbers
    //a array is of size n-1
    int n = arr.size()+1;
    int x1 = 1;
    for(int i = 2; i <= n; i++) {
        x1 = x1 ^ i;
    }
    //find xor of given elements
    int x2 = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        x2 = x2 ^ arr[i];
    }
    return x1 ^ x2;
}

int XOR::FindSingleNumber(const vector<int>& arr) {
    int x1 = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        x1 = x1 ^ arr[i];
    }
    return x1;
}

vector<int> XOR::FindTwoSingleNumbers(const vector<int>& arr) {
    int x1 = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        x1 = x1 ^ arr[i];
    }
    //x1 contains both numbers; need to find rightmost bit which is set; means both nums were diff;
    int rightMostBit = 1;
    while((rightMostBit & x1) == 0) {
        rightMostBit = rightMostBit << 1;
    }
    int num1 = 0, num2 = 0;
    for(auto num: arr) {
        if((rightMostBit & num) != 0) {
            num1 = num ^ num1;
        } else {
            num2 = num ^ num2;
        }
    }
    return vector<int>{num1, num2};
}

int XOR::CalculateComplement(int num) {
    int bitcount = 0;
    int n = num;
    while(n>0) {
        bitcount++;
        n = n >> 1;
    }
    int bitset = pow(2, bitcount) - 1;
    return num ^ bitset;
}

void XOR::Print(const vector<vector<int>> arr) {
    for(int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> XOR::FlipAndInvertImage(vector<vector<int>>& arr) {
    int s = arr[0].size();
    for(int row = 0; row < arr.size(); row++) {
        for(int col = 0; col < (s+1)/2; ++col) {
            int tmp = arr[row][col] ^ 1;
            arr[row][col] = arr[row][s- 1 - col] ^ 1;
            arr[row][s- 1 - col] = tmp;
        }
    }
    return arr;
}

#ifndef XOR_H
#define XOR_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class XOR {
    public:
        static int FindMissingNumber(const vector<int>& arr);
        static int FindSingleNumber(const vector<int>& arr);
        static vector<int> FindTwoSingleNumbers(const vector<int>& arr);
        static int CalculateComplement(int num);
        static void Print(const vector<vector<int>> arr);
        static vector<vector<int>> FlipAndInvertImage(vector<vector<int>>& arr);
};


#endif
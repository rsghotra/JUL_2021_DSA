#ifndef TOPK_H
#define TOPK_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TopK {
    private:
        struct ValCompare {
            bool operator()(const int& x, const int& y){return x > y;}
        };
    public:
        static vector<int> FindKLargestNumbers(const vector<int>& nums, int k);
};


#endif
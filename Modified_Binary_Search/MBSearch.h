#ifndef MBSEARCH_H
#define MBSEARCH_H
#include<vector>
#include<iostream>
using namespace std;

class MBSearch {
  public:
    static int OrderAgnostic(const vector<int>& arr, int key);
    static int FindCeiling(const vector<int>& arr, int key);
    static int FindFloor(const vector<int>& arr, int key);
    static char NextLetter(const vector<char>& arr, char key);
};

#endif
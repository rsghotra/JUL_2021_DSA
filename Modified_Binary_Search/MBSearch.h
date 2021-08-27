#ifndef MBSEARCH_H
#define MBSEARCH_H
#include<vector>
#include<iostream>
using namespace std;

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class MBSearch {
  public:
    static int OrderAgnostic(const vector<int>& arr, int key);
    static int FindCeiling(const vector<int>& arr, int key);
    static int FindFloor(const vector<int>& arr, int key);
    static char NextLetter(const vector<char>& arr, char key);
    static pair<int, int> NumberRange(const vector<int>& arr, int key);
    static int SearchRange(const vector<int>& arr, int key, bool maxIndex);
    static int SearchInfinite(ArrayReader* reader, int key);
    static int BinarySearchStandard(ArrayReader* reader, int key, int start, int end);
    static int MinimumDifferenceEle(const vector<int>& arr, int key);
};

#endif
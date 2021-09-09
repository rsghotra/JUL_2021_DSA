#include "TopK.h"

struct NumCompare {
    bool operator()(const int& x, const int& y){return x > y;}
};

vector<int> TopK::FindKLargestNumbers(const vector<int>& input, int k) {
    vector<int> minHeap(input.begin(), input.begin() + k);
    make_heap(minHeap.begin(), minHeap.end(), NumCompare());
    for(int i = k; i < input.size(); i++) {
        if(input[i] > minHeap.front()) {
            pop_heap(minHeap.begin(), minHeap.end(), NumCompare());
            minHeap.pop_back();
            minHeap.push_back(input[i]);
            push_heap(minHeap.begin(), minHeap.end(), NumCompare());
        }
    }
    return minHeap;
}


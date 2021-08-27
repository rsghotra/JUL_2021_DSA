#include "MBSearch.h"

int MBSearch::OrderAgnostic(const vector<int>& arr, int key) {
    if(arr.size() == 0) return -1;
    bool isAscending = arr[0] < arr[arr.size() -1];
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(isAscending) {
            if(key < arr[mid]) {
                end = mid-1;
            } else if(key > arr[mid]) {
                start = mid+1;
            } else {
                return mid;
            }
        } else {
            if(key < arr[mid]) {
                start = mid+1;
            } else if(key > arr[mid]) {
                end = mid-1;
            } else {
                return mid;
            }
        }
    }
    return -1;
}

int MBSearch::FindCeiling(const vector<int>& arr, int key) {
    if(arr.size() == 0) return -1;
    bool isAscending = arr[0] < arr[arr.size() -1];
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(isAscending) {
            if(key < arr[mid]) {
                end = mid-1;
            } else if(key > arr[mid]) {
                start = mid+1;
            } else {
                return key;
            }
        } else {
            if(key < arr[mid]) {
                start = mid+1;
            } else if(key > arr[mid]) {
                end = mid-1;
            } else {
                return key;
            } 
        }
    }
    return start;
}

int MBSearch::FindFloor(const vector<int>& arr, int key) {
    if(arr.size() == 0) return -1;
    bool isAscending = arr[0] < arr[arr.size() -1];
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(isAscending) {
            if(key < arr[mid]) {
                end = mid-1;
            } else if(key > arr[mid]) {
                start = mid+1;
            } else {
                return key;
            }
        } else {
            if(key < arr[mid]) {
                start = mid+1;
            } else if(key > arr[mid]) {
                end = mid-1;
            } else {
                return key;
            } 
        }
    }
    return end; 
}

char MBSearch::NextLetter(const vector<char>&, char key) {
    //if key is greater than last letter or smaller than first letter then the answer is the first key
}

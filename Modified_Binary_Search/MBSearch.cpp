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

char MBSearch::NextLetter(const vector<char>& letters, char key) {
    //if key is greater than last letter or smaller than first letter then the answer is the first key
    if(key < letters[0] || key > letters[letters.size() - 1]) {
        return letters[0];
    }
    int start = 0;
    int end = letters.size()-1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(key <letters[mid]) {
            end = mid-1;
        } else {    
            start = mid+1;
        }
    }
    return letters[start%letters.size()];
}


pair<int, int> MBSearch::NumberRange(const vector<int>& arr, int key) {
    pair<int, int> result(-1,-1);
    result.first = SearchRange(arr, key, false);
    if(result.first != -1) {
        result.second = SearchRange(arr, key, true);
    }
    return result;
}

int MBSearch::SearchRange(const vector<int>& arr, int key, bool huntingMaxIndex) {
    int keyIndex  = 1;
    int start = 0; int end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(arr[mid] < key) {
            end = mid-1;
        } else if(arr[mid] > key) {
            start = mid+1;
        } else {
            keyIndex = mid;
            if(huntingMaxIndex) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
    }
    return keyIndex;
}

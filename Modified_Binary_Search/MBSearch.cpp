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

int MBSearch::SearchInfinite(ArrayReader* reader, int key) {
    int start = 0, end = 1;
    while(reader->get(end) < key) {
        int newStart = end+1;
        end += (end-start+1)*2;
        start = newStart;
    }
    return BinarySearchStandard(reader, key, start, end);
}

int MBSearch::BinarySearchStandard(ArrayReader* reader, int key, int start, int end) {
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(key < reader->get(mid)) {
            end = mid-1;
        } else if(key > reader->get(mid)) {
            start = mid+1;
        } else {
            return mid;
        }
    }
    return -1;
}

int MBSearch::MinimumDifferenceEle(const vector<int>& arr, int key) {
    if(key < arr[0]) return arr[0];
    if(key > arr[arr.size()-1]) return arr[arr.size()-1];
    int start = 0, end = arr.size()-1;
    while(start<=end) {
        int mid = start +(end-start)/2;
        if(key < arr[mid]) {
            end = mid-1;
        } else if(key > arr[mid]) {
            start = mid+1;
        } else {
            return arr[mid];
        }
    }
    if((arr[start] - key) < (key - arr[end])) {
        return arr[start];
    } 
    return arr[end];
}

int MBSearch::FindMaxInBitonicArray(const vector<int>& arr) {
    int start = 0;
    int end = arr.size()-1;

    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[mid+1]) {
            end = mid;
        } else {
            //peak must be after mid
            start = mid+1;
        }
    }
    return arr[start];
}

int MBSearch::FindMaxIndexBitonicArray(const vector<int>& arr) {
    int start = 0;
    int end = arr.size()-1;

    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[mid+1]) {
            end = mid;
        } else {
            //peak must be after mid
            start = mid+1;
        }
    }
    return start;
}

int MBSearch::OrderAgnostic(const vector<int>& arr, int key, int start, int end, bool ascending) {
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(ascending) {
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

int MBSearch::SearchBitonicArray(const vector<int>& arr, int key) {
    int maxIndex = FindMaxIndexBitonicArray(arr);
    int keyIndex = OrderAgnostic(arr, key, 0, maxIndex, true);
    if(keyIndex != -1) return keyIndex;
    return OrderAgnostic(arr, key, maxIndex+1, arr.size()-1, false);
}

int MBSearch::SearchRotatedArray(const vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() -1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(arr[mid] == key) return mid;
        //find out which side is sorted, left side sorted
        if(arr[start] <= arr[mid]) {
            //check where value exists
            if(key >= arr[start] && key < arr[mid]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        } else {
            if(key > arr[mid] && key <= arr[end]) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
    }
    return -1;
}

int MBSearch::SearchRotatedWithDuplicate(const vector<int>& arr, int key) {
    int start = 0, end = arr.size()-1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(arr[mid] == key) return mid;
        if((arr[start] == arr[mid]) && (arr[mid] == arr[end])) {
            ++start;
            --end;
        } else if(arr[start] <= arr[mid]) {
            if(key >= arr[start] && key < arr[mid]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        } else {
            if(key > arr[mid] && key <= arr[end]) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
    }
    return -1;
}

int MBSearch::RotationCountOfRotatedArray(const vector<int>& arr) {
    int start = 0;
    int end = arr.size() -1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        //if mid is greater than the next element
        if(mid < end && arr[mid] > arr[mid+1]) {
            return mid+1;
        }
        //if mid is smaller than the previous element
        if(mid > start && arr[mid-1] > arr[mid]) {
            return mid;
        }
        //split call;
        if(arr[start] < arr[mid]) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return 0;
}

int MBSearch::RotationCountWithDuplicates(const vector<int>& arr) {
    int start = 0;
    int end = arr.size()-1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(mid < end && arr[mid] > arr[mid+1]) {
            return mid+1;
        }
        if(mid > start && arr[mid-1] > arr[mid]) {
            return mid;
        }
        if(arr[start] == arr[mid] && (arr[mid] == arr[end])) {
            if(arr[start] > arr[start+1]) {
                return start+1;
            }
            start++;
            if(arr[end] < arr[end-1]) {
                return end;
            }
            end--;
        } else if(arr[start] < arr[mid] || ((arr[start] == arr[mid]) && (arr[mid] > arr[end]))) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return 0;
}

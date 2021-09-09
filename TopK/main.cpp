#include "TopK.h"


int main() {
    vector<int> result = TopK::FindKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
    cout << "Here are the top K numbers: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = TopK::FindKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
    cout << "Here are the top K numbers: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

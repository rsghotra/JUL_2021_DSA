#include "XOR.h"

int main() {
    cout << "XORed" << endl;
    vector<int> v1 = {1, 5, 2, 6, 4};
    cout << "Missing number is: " << XOR::FindMissingNumber(v1);
    cout << XOR::FindSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;

    vector<int> v2 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
    vector<int> result = XOR::FindTwoSingleNumbers(v2);
    cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

    vector<int> v3 = {2, 1, 3, 2};
    result = XOR::FindTwoSingleNumbers(v3);
    cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

    cout << "Bitwise complement is: " << XOR::CalculateComplement(8) << endl;
    cout << "Bitwise complement is: " << XOR::CalculateComplement(10) << endl;

    vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
    XOR::Print(XOR::FlipAndInvertImage(arr));
    cout << "\n";

    cout << "Flipping and inverting image" << endl;
    vector<vector<int>> arr2 = vector<vector<int>>{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    XOR::Print(XOR::FlipAndInvertImage(arr2));
    return 0;
}
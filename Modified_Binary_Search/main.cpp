#include "MBSearch.h"

int main() {
  cout << MBSearch::OrderAgnostic(vector<int>{4, 6, 10}, 10) << endl;
  cout << MBSearch::OrderAgnostic(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << MBSearch::OrderAgnostic(vector<int>{10, 6, 4}, 10) << endl;
  cout << MBSearch::OrderAgnostic(vector<int>{10, 6, 4}, -4) << endl;

  cout << MBSearch::FindCeiling(vector<int>{4, 6, 10}, 6) << endl;
  cout << MBSearch::FindCeiling(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MBSearch::FindCeiling(vector<int>{4, 6, 10}, 17) << endl;
  cout << MBSearch::FindCeiling(vector<int>{4, 6, 10}, -1) << endl;

  cout << MBSearch::FindFloor(vector<int>{4, 6, 10}, 6) << endl;
  cout << MBSearch::FindFloor(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MBSearch::FindFloor(vector<int>{4, 6, 10}, 17) << endl;
  cout << MBSearch::FindFloor(vector<int>{4, 6, 10}, -1) << endl;

  cout << MBSearch::NextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << MBSearch::NextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << MBSearch::NextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << MBSearch::NextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;

  pair<int, int> result = MBSearch::NumberRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = MBSearch::NumberRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = MBSearch::NumberRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;

  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << MBSearch::SearchInfinite(reader, 16) << endl;
  cout << MBSearch::SearchInfinite(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << MBSearch::SearchInfinite(reader, 15) << endl;
  cout << MBSearch::SearchInfinite(reader, 200) << endl;
  delete reader;
  
  cout << MBSearch::MinimumDifferenceEle(vector<int>{4, 6, 10}, 7) << endl;
  cout << MBSearch::MinimumDifferenceEle(vector<int>{4, 6, 10}, 4) << endl;
  cout << MBSearch::MinimumDifferenceEle(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MBSearch::MinimumDifferenceEle(vector<int>{4, 6, 10}, 17) << endl;

  cout << MBSearch::FindMaxInBitonicArray(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MBSearch::FindMaxInBitonicArray(vector<int>{3, 8, 3, 1}) << endl;
  cout << MBSearch::FindMaxInBitonicArray(vector<int>{1, 3, 8, 12}) << endl;
  cout << MBSearch::FindMaxInBitonicArray(vector<int>{10, 9, 8}) << endl;

  
  cout << MBSearch::SearchBitonicArray(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << MBSearch::SearchBitonicArray(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << MBSearch::SearchBitonicArray(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << MBSearch::SearchBitonicArray(vector<int>{10, 9, 8}, 10) << endl;

  cout << MBSearch::SearchRotatedArray(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << MBSearch::SearchRotatedArray(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;

  
  cout << MBSearch::SearchRotatedWithDuplicate(vector<int>{3, 7, 3, 3, 3}, 7) << endl;

  cout << "Searching Rotated without dups" << endl;
  cout << MBSearch::RotationCountOfRotatedArray(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << MBSearch::RotationCountOfRotatedArray(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << MBSearch::RotationCountOfRotatedArray(vector<int>{1, 3, 8, 10}) << endl;

  cout << "Searching Rotated WITH dups" << endl;
  cout << MBSearch::RotationCountWithDuplicates(vector<int>{3, 3, 7, 3}) << endl;
  return 0;
}
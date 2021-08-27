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
  cout << "Min diff ele" << endl;
  cout << MBSearch::MinimumDifferenceEle(vector<int>{4, 6, 10}, 7) << endl;
  cout << MBSearch::MinimumDifferenceEle(vector<int>{4, 6, 10}, 4) << endl;
  cout << MBSearch::MinimumDifferenceEle(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MBSearch::MinimumDifferenceEle(vector<int>{4, 6, 10}, 17) << endl;
  return 0;
}
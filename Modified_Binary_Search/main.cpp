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
  return 0;
}
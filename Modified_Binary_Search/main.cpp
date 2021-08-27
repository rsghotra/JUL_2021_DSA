#include "MBSearch.h"

int main() {
  cout << MBSearch::OrderAgnostic(vector<int>{4, 6, 10}, 10) << endl;
  cout << MBSearch::OrderAgnostic(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << MBSearch::OrderAgnostic(vector<int>{10, 6, 4}, 10) << endl;
  cout << MBSearch::OrderAgnostic(vector<int>{10, 6, 4}, -4) << endl;
  return 0;
}
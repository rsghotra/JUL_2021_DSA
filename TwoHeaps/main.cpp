#include "TwoHeaps.h"

int main() {
  TwoHeaps twoHeaps;
  twoHeaps.InsertNum(3);
  twoHeaps.InsertNum(1);
  cout << "The median is: " << twoHeaps.FindStreamMedian() << endl;
  twoHeaps.InsertNum(5);
  cout << "The median is: " << twoHeaps.FindStreamMedian() << endl;
  twoHeaps.InsertNum(4);
  cout << "The median is: " << twoHeaps.FindStreamMedian() << endl;

  TwoHeaps slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.FindSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = TwoHeaps();
  result = slidingWindowMedian.FindSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }

  int result1 =
      slidingWindowMedian.FindMaximumCapital(vector<int>{0, 1, 2}, vector<int>{1, 2, 3}, 2, 1);
  cout << "\nMaximum capital: " << result1 << endl;
  result1 = slidingWindowMedian.FindMaximumCapital(vector<int>{0, 1, 2, 3}, vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: ";
  cout << result1 << endl;
}
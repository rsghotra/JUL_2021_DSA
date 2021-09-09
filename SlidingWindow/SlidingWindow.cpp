#include "SlidingWindow.h"


void SlidingWindow::KSumAverage() {
	vector<double> result =
    SlidingWindow::KSumAverage(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
  	cout << "Averages of subarrays of size K: ";
	for (double d : result) {
		cout << d << " ";
	}
	cout << endl;
}

vector<double> SlidingWindow::KSumAverage(int K, const vector<int>& input) {
	vector<double> result;
	int windowStart = 0;
	int windowSum = 0;
	for(int windowEnd=0; windowEnd < int(input.size()); windowEnd++) {
		windowSum += input[windowEnd];
		
		if(windowEnd-windowStart+1==K) {
			result.push_back((1.0*windowSum)/K);
			windowSum -= input[windowStart];
			windowStart++;
		}
	}
	return result;
}
	
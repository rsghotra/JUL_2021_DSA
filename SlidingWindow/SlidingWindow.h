#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H
#include<iostream>
#include<vector>
using namespace std;

class SlidingWindow {
	private:
		static vector<double> KSumAverage(int K, const vector<int>& input);
	public:
		static void KSumAverage();
};
#endif
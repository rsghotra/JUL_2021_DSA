#ifndef TWOPOINTERS_H
#define TWOPOINTERS_H
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class TwoPointers {
	private:
		static pair<int, int> TargetSumHashMap(const vector<int>& input, int targetSum);
		static pair<int, int> TargetSum(const vector<int>& input, int targetSum);
		static int RemoveDuplicatesInplace1(vector<int>& input);
		static int RemoveDuplicatesInplace2(vector<int>& input);
		static vector<int> SquareSorted(const vector<int>& input);
		static vector<vector<int>> TripletsSumToZero(vector<int>& input);
		static void SearchPairs(const vector<int>& input, int targetSum, int left, vector<vector<int>>& triplets);
	public:
		static void TargetSumHashMap();
		static void TargetSum();
		static void RemoveDuplicatesInplace1();
		static void SquareSorted();
		//Triplets
		static void TripletsSumToZero();
};
#endif
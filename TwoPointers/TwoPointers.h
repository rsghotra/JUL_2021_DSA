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
		//triplets sum to zero
		static vector<vector<int>> TripletsSumToZero(vector<int>& input);
		static void SearchPairs(const vector<int>& input, int targetSum, int left, vector<vector<int>>& triplets);
		//triplet sum closest to target
		static void SearchClosest(vector<int>& input, int targetSum, int first, int left, int right, int& smallestDiff);
		static int TripletsSumCloseToTarget(vector<int>& input, int targetSum);
		//count triplets less than target
		static int  CountTripletsLessThanTarget(vector<int>& input, int targetSum);
		static void CountLess(vector<int>& input, int targetSum, int left, int& count);
		//search triplets less than target
		static vector<vector<int>> SearchTripletsLessThanTarget(vector<int>& input, int targetSum);
		static void SearchLess(vector<int>& input, int targetSum, int left, vector<vector<int>>& triplets);
		//subarrays product less than target
		static vector<vector<int>> SubarrayProductLessThanTarget(vector<int> input, int targetSum);
		//Dutch sort
		static void DutchFlag(vector<int>& input);
		static void Swap(vector<int>& input, int i, int j);
		//Quadruplets
		static vector<vector<int>> Quadruplets(vector<int>& input, int targetSum);
		static void SearchQuadruplets(vector<int>& input, int targetSum, int first, int second, vector<vector<int>>& quadruplets);
		//backspace compare;
		static bool BackspaceCompare(const string& str1, const string& str2);
		static int  NextValidIndex(const string& str, int index);
		static int  ShortestWindowSort(const vector<int>& input);
	public:
		static void TargetSumHashMap();
		static void TargetSum();
		static void RemoveDuplicatesInplace1();
		static void SquareSorted();
		//Triplets to zero
		static void TripletsSumToZero();
		//triplets to close to target solved by  targetDiff
		static void TripletsSumCloseToTarget();
		//triplets less than target
		static void CountTripletsLessThanTarget();
		static void SearchTripletsLessThanTarget();
		//subarrays with products less than a target: Sliding window + Two Pointers
		static void SubarrayProductLessThanTarget();
		static void DutchFlag();
		//Quadruplets
		static void Quadruplets();
		//BackSpace Compare
		static void BackspaceCompare();
		//Shortest Window Sort
		static void ShortestWindowSort();
};
#endif
#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class SlidingWindow {
	private:
		//fixed sliding window
		static vector<double> KSumAverage(int K, const vector<int>& input);
		static int KMaxSum(int K, const vector<int>& input);
		//dynamic sliding window
		static int MinSizeSubArraySum(int S, const vector<int>& nums);
		//dynamic window + hash table
		static int LongestSubstringWithKDistinctChars(const string& str, int k);
		static int FruitBasket(const vector<char>& fruits);
		//dynamic window + set
		static int NoRepeatSubstringMaxLength(const string& str);
		//dynamic window + maxFrequencyCount + character replacement
		static int KCharacterReplacements(const string& str, int K);
		static int LongestSubstringReplaceOnes(const vector<int>& input, int K);
		static bool PermutationExists(const string& str, const string& pattern);
		static vector<int> StringAnagrams(const string& str, const string& pattern);
		static string FindSubstring(const string& input, const string& pattern);
	public:
		//fixed window
		static void KSumAverage();
		static void KMaxSum();
		//dynamic sliding window
		static void MinSizeSubArraySum();
		//dynamic window + hash table;
		static void LongestSubstringWithKDistinctChars();
		static void FruitBasket();
		//dynamic window + set
		static void NoRepeatSubstringMaxLength();
		//dynamic window + maxFrequencyCount + character replacement
		static void KCharacterReplacements();
		static void LongestSubstringReplaceOnes();
		//Permutation Exissts: Dynamic Window + Frequency Map of Given 'Pattern' NOT INPUT
		static void PermutationExists();
		static void StringAnagrams();
		//Substring: Pattern Mapping, Dynamic Window
		static void FindSubstring();
};
#endif
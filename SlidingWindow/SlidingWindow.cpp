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

void SlidingWindow::KMaxSum() {
	cout << "Maximum sum of a subarray of size K: "
       << SlidingWindow::KMaxSum(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
  	cout << "Maximum sum of a subarray of size K: "
       << SlidingWindow::KMaxSum(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}

int SlidingWindow::KMaxSum(int K, const vector<int>& input) {
	int maxSum = INT32_MIN;
	int windowStart = 0;
	int windowSum = 0;
	for(int windowEnd = 0; windowEnd < int(input.size()); windowEnd++) {
		windowSum += input[windowEnd];
		if(windowEnd - windowStart + 1 == K) {
			maxSum = max(maxSum, windowSum);
			windowSum -= input[windowStart];
			windowStart++;
		}
	}
	return maxSum;
}

int SlidingWindow::MinSizeSubArraySum(int S, const vector<int>& input) {
	int windowSum = 0;
	int windowStart = 0;
	int minLength = INT32_MAX;

	for(int windowEnd = 0; windowEnd < int(input.size()); windowEnd++) {
		windowSum += input[windowEnd];
		while( windowSum >= S ) {
			minLength = min(minLength, windowEnd - windowStart + 1);
			windowSum -= input[windowStart];
			windowStart++;
		}
	}
	return minLength == INT32_MAX ? 0:minLength;
}

void SlidingWindow::MinSizeSubArraySum() {
	int result = SlidingWindow::MinSizeSubArraySum(7, vector<int>{2, 1, 5, 2, 3, 2});
	cout << "Smallest subarray length: " << result << endl;
	result = SlidingWindow::MinSizeSubArraySum(7, vector<int>{2, 1, 5, 2, 8});
	cout << "Smallest subarray length: " << result << endl;
	result = SlidingWindow::MinSizeSubArraySum(8, vector<int>{3, 4, 1, 1, 6});
	cout << "Smallest subarray length: " << result << endl;
}

int SlidingWindow::LongestSubstringWithKDistinctChars(const string& str, int k) {
	unordered_map<char, int> frequencies;
	int windowStart = 0;
	int maxLength = INT32_MIN;
	for(int windowEnd = 0; windowEnd < int(str.size()); windowEnd++) {
		frequencies[str[windowEnd]]++;
		while(int(frequencies.size()) > k) {
			frequencies[str[windowStart]]--;
			if(frequencies[str[windowStart]] == 0) {
				frequencies.erase(str[windowStart]);
			}
			windowStart++;
		}
		maxLength = max(maxLength, windowEnd-windowStart+1);
	}
	return maxLength == INT32_MIN ? str.length() : maxLength;
}

int SlidingWindow::FruitBasket(const vector<char>& fruits) {
	int windowStart = 0;
	unordered_map<char, int> frequencies;
	int maxBucketSize = INT32_MIN;
	for(int windowEnd = 0; windowEnd < int(fruits.size()); windowEnd++) {
		frequencies[fruits[windowEnd]]++;
		while(int(frequencies.size()) > 2) {
			frequencies[fruits[windowStart]]--;
			if(frequencies[fruits[windowStart]] == 0) {
				frequencies.erase(fruits[windowStart]);
			}
			windowStart++;
		}
		maxBucketSize = max(maxBucketSize, windowEnd - windowStart + 1);
	}
	return maxBucketSize;
}

int SlidingWindow::NoRepeatSubstringMaxLength(const string& str) {
	int windowStart = 0;
	int windowEnd = 0;
	int maxLength = 0;
	set<char> entries;
	while(windowEnd < int(str.size())) {
		if(entries.find(str[windowEnd]) != entries.end()) {
			entries.erase(str[windowStart]);
			windowStart++;
		} else {
			entries.insert(str[windowEnd]);
			maxLength = max(maxLength, windowEnd - windowStart + 1);
			windowEnd++;
		}
	}
	return maxLength;
}

int SlidingWindow::KCharacterReplacements(const string& str, int K) {
	int windowStart = 0;
	int maxLength = 0;
	int maxCharCount = 0;
	unordered_map<char, int> frequencies;
	for(int windowEnd = 0; windowEnd < int(str.size()); windowEnd++) {
		frequencies[str[windowEnd]]++;
		maxCharCount = max(maxCharCount, frequencies[str[windowEnd]]);

		if(windowEnd - windowStart + 1 - maxCharCount > K) {
			frequencies[str[windowStart]]--;
			windowStart++;
		}
		maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
	return maxLength;
}

int SlidingWindow::LongestSubstringReplaceOnes(const vector<int>& input, int K) {
	int windowStart = 0;
	int maxLength = 0;
	int maxOnesCount = 0;
	for(int windowEnd = 0; windowEnd < int(input.size()); windowEnd++) {
		if(input[windowEnd] == 1) {
			maxOnesCount++;
		}
		if(windowEnd - windowStart + 1 - maxOnesCount > K) {
			if(input[windowStart] == 1) {
				maxOnesCount--;
			}
			windowStart++;
		}
		maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
	return maxLength;
}

bool SlidingWindow::PermutationExists(const string& str, const string& pattern) {
	unordered_map<char, int> frequencies;
	for(char ch: pattern) {
		frequencies[ch]++;
	}
	int windowStart = 0;
	int matchCount = 0;
	vector<int> result;
	for(int windowEnd = 0; windowEnd < int(str.size()); windowEnd++) {
		if(frequencies.find(str[windowEnd]) != frequencies.end()) {
			frequencies[str[windowEnd]]--;
			if(frequencies[str[windowEnd]] == 0) {
				matchCount++;
			}
		}
		if(matchCount == (int)frequencies.size()) {
			return true;
		}
		if(windowEnd - windowStart + 1 >= int(pattern.length())) {
			if(frequencies.find(str[windowStart]) != frequencies.end()) {
				if(frequencies[str[windowStart]] == 0) {
					matchCount--;
				}
				frequencies[str[windowStart]]++;
			}
			windowStart++;	
		}
	}
	return false;
}

void SlidingWindow::LongestSubstringWithKDistinctChars() {
	cout << "Length of the longest substring: " << SlidingWindow::LongestSubstringWithKDistinctChars("araaci", 2)
       << endl;
  	cout << "Length of the longest substring: " << SlidingWindow::LongestSubstringWithKDistinctChars("araaci", 1)
       << endl;
  	cout << "Length of the longest substring: " << SlidingWindow::LongestSubstringWithKDistinctChars("cbbebi", 3)
       << endl;
}

void SlidingWindow::FruitBasket() {
 	cout << "Maximum number of fruits: "
       	<< SlidingWindow::FruitBasket(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
  	cout << "Maximum number of fruits: "
       	<< SlidingWindow::FruitBasket(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}

void SlidingWindow::NoRepeatSubstringMaxLength() {
	cout << "Length of the longest substring: " << SlidingWindow::NoRepeatSubstringMaxLength("aabccbb") << endl;
  	cout << "Length of the longest substring: " << SlidingWindow::NoRepeatSubstringMaxLength("abbbb") << endl;
  	cout << "Length of the longest substring: " << SlidingWindow::NoRepeatSubstringMaxLength("abccde") << endl;
}

void SlidingWindow::KCharacterReplacements() {
	cout << KCharacterReplacements("aabccbb", 2) << endl;
  	cout << KCharacterReplacements("abbcb", 1) << endl;
  	cout << KCharacterReplacements("abccde", 1) << endl;
}

void SlidingWindow::LongestSubstringReplaceOnes() {
	cout << LongestSubstringReplaceOnes(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  	cout << LongestSubstringReplaceOnes(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}

void SlidingWindow::PermutationExists() {
	cout << "Permutation exist: " << SlidingWindow::PermutationExists("oidbcaf", "abc") << endl;
 	cout << "Permutation exist: " << SlidingWindow::PermutationExists("odicf", "dc") << endl;
  	cout << "Permutation exist: " << SlidingWindow::PermutationExists("bcdxabcdy", "bcdyabcdx") << endl;
  	cout << "Permutation exist: " << SlidingWindow::PermutationExists("aaacb", "abc") << endl;
}

vector<int> SlidingWindow::StringAnagrams(const string& str, const string& pattern) {
	unordered_map<char, int> frequencies;
	for(char ch: pattern) {
		frequencies[ch]++;
	}
	int windowStart = 0;
	int matchCount = 0;
	vector<int> result;
	for(int windowEnd = 0; windowEnd < int(str.size()); windowEnd++) {
		if(frequencies.find(str[windowEnd]) != frequencies.end()) {
			frequencies[str[windowEnd]]--;
			if(frequencies[str[windowEnd]] == 0) {
				matchCount++;
			}
		}
		if(matchCount == (int)frequencies.size()) {
			result.push_back(windowStart);
		}
		if(windowEnd - windowStart + 1 >= int(pattern.length())) {
			if(frequencies.find(str[windowStart]) != frequencies.end()) {
				if(frequencies[str[windowStart]] == 0) {
					matchCount--;
				}
				frequencies[str[windowStart]]++;
			}
			windowStart++;	
		}
	}
	return result;
}

void SlidingWindow::StringAnagrams() {
	auto result = StringAnagrams("ppqp", "pq");
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	result = StringAnagrams("abbcabc", "abc");
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}

string SlidingWindow::FindSubstring(const string& input, const string& pattern) {
	int windowStart = 0;
	int minLength = INT32_MAX;
	int subStrStart = 0;
	int matchCount = 0;
	unordered_map<char, int> mappings;
	//watch out pattern
	for(char ch: pattern) {
		mappings[ch]++;
	}
	
	for(int windowEnd = 0; windowEnd < int(input.size()); windowEnd++) {
		if(mappings.find(input[windowEnd]) != mappings.end()) {
			mappings[input[windowEnd]]--;
			if(mappings[input[windowEnd]] >= 0) {
				matchCount++;
			}
		}
		//watch out
		while(matchCount == int(pattern.length())) {
			minLength = min(minLength, windowEnd - windowStart + 1);
			subStrStart = windowStart;
			if(mappings.find(input[windowStart]) != mappings.end()) {
				if(mappings[input[windowStart]] == 0) {
					matchCount--;
				}
				mappings[input[windowStart]]++;
			}
		}
	}
	return minLength > int(input.length()) ? "" : input.substr(subStrStart, minLength);
}

void SlidingWindow::FindSubstring() {
	cout << SlidingWindow::FindSubstring("aabdec", "abc") << endl;
  	cout << SlidingWindow::FindSubstring("abdbca", "abc") << endl;
  	cout << SlidingWindow::FindSubstring("adcad", "abc") << endl;
}
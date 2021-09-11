#include "TwoPointers.h"

pair<int, int> TwoPointers::TargetSumHashMap(const vector<int>& input, int targetSum) {
	unordered_map<int, int> mappings;
	for(int i = 0; i < (int)input.size(); i++) {
		if(mappings.find(targetSum - input[i]) != mappings.end()) {
			return make_pair(i, mappings[targetSum - input[i]]);
		} else {
			mappings[input[i]] = i;
		}		
	}
	return make_pair(-1, -1);
}

pair<int, int> TwoPointers::TargetSum(const vector<int>& input, int targetSum) {
	int leftPtr = 0;
	int rightPtr = input.size() - 1;
	//strictly less as we need two diff numbers
	while(leftPtr < rightPtr) {
		if(input[leftPtr] + input[rightPtr] == targetSum) {
			return make_pair(leftPtr, rightPtr);
		} else if(input[leftPtr] + input[rightPtr] > targetSum) {
			rightPtr--;
		} else {
			leftPtr++;
		}
	}
	return make_pair(-1, -1);
}

int TwoPointers::RemoveDuplicatesInplace1(vector<int>& input) {
	int i = 0;
	while(i < (int)input.size() - 1) {
		if(input.at(i) == input.at(i+1)) {
			input.erase(input.begin() + i);
		} else {
			i++;
		}
	}
	return input.size();
}

vector<int> TwoPointers::SquareSorted(const vector<int>& input) {
	int highIndex = input.size() - 1;
	vector<int> result(input.size());
	int leftPtr = 0;
	int rightPtr = input.size() - 1;
	while(leftPtr < rightPtr) {
		int leftSqr = input[leftPtr] * input[leftPtr];
		int rightSqr = input[rightPtr] * input[rightPtr];
		if(leftSqr > rightSqr) {
			result[highIndex] = leftSqr;
			leftPtr++;
			highIndex--;
		} else {
			result[highIndex] = rightSqr;
			rightPtr--;
			highIndex--;
		}
	}
	return result;
}

void TwoPointers::TargetSumHashMap() {
	auto result = TargetSumHashMap(vector<int>{1, 2, 3, 4, 6}, 6);
  	cout << "Pair with target sum - hashmap: [" << result.first << ", " << result.second << "]" << endl;
  	result = TargetSumHashMap(vector<int>{2, 5, 9, 11}, 11);
  	cout << "Pair with target sum - hashmap: [" << result.first << ", " << result.second << "]" << endl;	
}

void TwoPointers::TargetSum() {
	auto result = TargetSum(vector<int>{1, 2, 3, 4, 6}, 6);
  	cout << "Pair with target sum - normal: [" << result.first << ", " << result.second << "]" << endl;
  	result = TargetSum(vector<int>{2, 5, 9, 11}, 11);
  	cout << "Pair with target sum - normal: [" << result.first << ", " << result.second << "]" << endl;	
}

void TwoPointers::SquareSorted() {
	vector<int> result = SquareSorted(vector<int>{-2, -1, 0, 2, 3});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	result = SquareSorted(vector<int>{-3, -1, 0, 1, 2});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}

vector<vector<int>> TwoPointers::TripletsSumToZero(vector<int>& input) {
	//DO NOT FUCKING FORGET TO SORT
	std::sort(input.begin(), input.end());
	vector<vector<int>> triplets;
	for(int i = 0; i < int(input.size()) - 2; i++) {
		if(i > 0 && input[i] == input[i-1]) { //duplicate
			continue;
		}
		SearchPairs(input, -input[i], i+1, triplets);
	}
	return triplets;
}

void TwoPointers::SearchPairs(const vector<int>& input, int targetSum, int left, vector<vector<int>>& triplets) {
	int right = input.size() - 1;
	while(left < right) {
		if(input[left] + input[right] == targetSum) {
			triplets.push_back({-targetSum, input[left], input[right]});
			left++;
			right--;
			while(left < right && input[left] == input[left-1]) {
				left++;
			}
			while(left < right && input[right] == input[right+1]) {
				right--;
			}
		} else if(input[left] + input[right] < targetSum) {
			left++;
		} else {
			right--;
		}
	}
}

void TwoPointers::TripletsSumToZero() {
	vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
	auto result = TripletsSumToZero(vec);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
	}
	cout << endl;

	vec = {-5, 2, -1, -2, 3};
	result = TripletsSumToZero(vec);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
	}
}


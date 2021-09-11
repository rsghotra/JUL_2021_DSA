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
	std::sort(input.begin(), input.end());
	vector<vector<int>> triplets;
	for(int i=0; i < int(input.size()) - 2; i++) {
		if(i>0 && input[i-1] != input[i]) {
			continue;
		}
		SearchPairs(input, -input[i], i+1, triplets);
	}
	return triplets;
}

void TwoPointers::SearchPairs(const vector<int>& input, int targetSum, int left, vector<vector<int>>& triplets) {
	int first = input[left-1];
	int right = input.size() - 1;
	while(left < right) {
		if(input[left] + input[right] == targetSum) {
			triplets.push_back({first, input[left], input[right]});
			left++;
			right--;
			while(left < right && input[left-1] == input[left]) {
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
	cout << "Triplets sum to zero" << endl;
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

int TwoPointers::TripletsSumCloseToTarget(vector<int>& input, int targetSum) {
	std::sort(input.begin(), input.end());
	int smallestDiff = INT32_MAX;
	for(int i = 0; i < int(input.size()) - 2; i++) {
		int first = i;
		int left = i+1;
		int right = input.size() - 1;
		SearchClosest(input, targetSum, first, left, right, smallestDiff);
		if(smallestDiff == 0) break;
	}
	return targetSum - smallestDiff;
}

void TwoPointers::SearchClosest(vector<int>& input, int targetSum, int first, int left, int right, int& smallestDiff) {
	while(left < right) {
		int targetDiff = targetSum - input[first] - input[left] - input[right];
		if(targetDiff == 0) { //tripletFound;
			smallestDiff = 0;
			return;
		}
		smallestDiff = min(abs(smallestDiff), abs(targetDiff));
		if(targetDiff > 0) {
			left++;
		}
		if(targetDiff < 0) {
			right--;
		}
	}
}

void TwoPointers::TripletsSumCloseToTarget() {
	vector<int> vec = {-2, 0, 1, 2};
	cout << endl;
  	cout << TripletsSumCloseToTarget(vec, 2) << endl;
  	vec = {-3, -1, 1, 2};
  	cout << TripletsSumCloseToTarget(vec, 1) << endl;
  	vec = {1, 0, 1, 1};
  	cout << TripletsSumCloseToTarget(vec, 100) << endl;
}


int TwoPointers::CountTripletsLessThanTarget(vector<int>& input, int targetSum) {
	//do not forget to sort yaar
	std::sort(input.begin(), input.end());
	int count = 0;
	//X+Y+Z = target; => Y+Z = target - X
	for(int i = 0; i < int(input.size()) - 2; i++) {
		CountLess(input, targetSum - input[i], i+1, count);
	}
	return count;
}

void TwoPointers::CountLess(vector<int>& input, int targetSum, int left, int& count) {
	int right = input.size() - 1 ;
	while(left < right) {
		if(input[left] + input[right] < targetSum) {
			count += right - left;
			left++;
		} else {
			right--;
		}
	}
}

void TwoPointers::CountTripletsLessThanTarget() {
	cout << "Number of triplets less than target: " << endl;
	vector<int> vec = {-1, 0, 2, 3};
  	cout << CountTripletsLessThanTarget(vec, 3) << endl;
  	vec = {-1, 4, 2, 1, 3};
  	cout << CountTripletsLessThanTarget(vec, 5) << endl;
}

vector<vector<int>> TwoPointers::SearchTripletsLessThanTarget(vector<int>& input, int targetSum) {
	std::sort(input.begin(), input.end());
	vector<vector<int>> triplets;
	for(int i = 0; i < int(input.size()) - 2; i++) {
		SearchLess(input, targetSum - input[i], i+1, triplets);
	}
	return triplets;
}

void TwoPointers::SearchLess(vector<int>& input, int targetSum, int left, vector<vector<int>>& triplets) {
	int right = input.size() - 1;
	int first = left - 1;
	while(left < right) {
		if(input[left] + input[right] < targetSum) {
			// since arr[right] >= arr[left], therefore, we can replace arr[right] by any number between
        	// left and right to get a sum less than the target sum
			for(int i = right; i > left; i--) {
				triplets.push_back({input[first], input[left], input[i]});
			}
			left++;
		} else {
			right--;
		}
	}
}

void TwoPointers::SearchTripletsLessThanTarget() {
	cout << "Triplets less than target found: " << endl;
	vector<int> vec = {-1, 0, 2, 3};
	auto result = SearchTripletsLessThanTarget(vec, 3);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
	}
	cout << endl;

	vec = {-1, 4, 2, 1, 3};
	result = SearchTripletsLessThanTarget(vec, 5);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
	}
}


vector<vector<int>> TwoPointers::SubarrayProductLessThanTarget(vector<int> input, int targetSum) {
	//mix of sliding window + two pointers;
	int windowStart = 0;
	int product = 1;
	vector<vector<int>> result;
	for(int windowEnd = 0; windowEnd < int(input.size()); windowEnd++) {
		product = product * input[windowEnd];
		while(product >= targetSum && windowStart < int(input.size())) {
			product = product/input[windowStart]; //taking the num out of window;
			windowStart++;
		}
		//we have the appropriate window now;
		vector<int> current;
		for(int i = windowEnd; i >= windowStart; i--) {
			current.push_back(input[i]);
		}
		result.push_back(current);
	}
	return result;
}

void TwoPointers::SubarrayProductLessThanTarget() {
	vector<int> vect{2, 5, 3, 10};
	auto result = SubarrayProductLessThanTarget(vect, 30);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
	}
	cout << endl;

	result = SubarrayProductLessThanTarget(vector<int>{8, 2, 6, 5}, 50);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
	}
}

void TwoPointers::Swap(vector<int>& input, int i, int j) {
	int temp = input[i];
	input[i] = input[j];
	input[j] = temp;
}

void TwoPointers::DutchFlag(vector<int>& input) {
	int left = 0;
	int right = input.size() - 1;
	int i = 0;
	while(i <= right) {
		if(input[i] == 0) {
			Swap(input, i, left);
			left++;
			i++;
		} else if(input[i] == 1) {
			i++;
		} else {
			Swap(input, i, right); //do not increment i as Swapped element is coming from the future;
			right--;
		}
	}
}

void TwoPointers::DutchFlag() {
	cout << "\nThis is Dutch Sort" << endl;
	vector<int> arr = {1, 0, 2, 1, 0};
	DutchFlag(arr);
	for (auto num : arr) {
		cout << num << " ";
	}
	cout << endl;

	arr = vector<int>{2, 2, 0, 1, 2, 0};
	DutchFlag(arr);
	for (auto num : arr) {
		cout << num << " ";
	}
}

vector<vector<int>> TwoPointers::Quadruplets(vector<int>& input, int targetSum) {
	sort(input.begin(), input.end());
	vector<vector<int>> result;
	for(int i = 0; i < int(input.size() - 3); i++) {
		if(i > 0 && input[i-1] == input[i]) {
			continue;
		}
		for(int j = i+1; j < int(input.size()) - 2; j++) {
			if(j > i+1 && input[j-1] == input[j]) {
				continue;
			}
			SearchQuadruplets(input, targetSum - input[i] - input[j], i, j, result);
		}
	}
	return result;
}

void TwoPointers::SearchQuadruplets(vector<int>& input, int targetSum, int first, int second, vector<vector<int>>& quadruplets) {
	int left = second + 1;
	int right = input.size() - 1;
	while(left < right) {
		if(input[left] + input[right] == targetSum) {
			quadruplets.push_back({input[first], input[second], input[left], input[right]});
			left++;
			right--;
			while(left < right && input[left-1] == input[left]) {
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

void TwoPointers::Quadruplets() {
	cout << "\nFinding Quadruplets" << endl;
	vector<int> vec = {4, 1, 2, -1, 1, -3};
	auto result = Quadruplets(vec, 1);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
	}
	cout << endl;

	vec = {2, 0, -1, 1, -2, 2};
	result = Quadruplets(vec, 2);
	for (auto vec : result) {
		cout << "[";
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << "]";
  }
}

bool TwoPointers::BackspaceCompare(const string& str1, const string& str2) {
	int ptr1 = str1.length() - 1;
	int ptr2 = str2.length() - 1;
	while(ptr1 >= 0 || ptr2 >= 0) {
		int I1 = NextValidIndex(str1, ptr1);
		int I2 = NextValidIndex(str2, ptr2);

		if(I1 < 0 && I2 < 0) {
			return true;
		}

		if(I1 < 0 || I2 < 0) {
			return false;
		}

		if(str1[I1] != str2[I2]) {
			return false;
		}
		//it means str1[I1] == str2[I2]; move to previous index
		ptr1 = --I1;
		ptr2 = --I2;
	}
	return true;
}

int TwoPointers::NextValidIndex(const string& str, int index) {
	int backspace = 0;
	while(index >= 0) {
		if(str[index] == '#') {
			backspace++;
		} else if(backspace > 0) {
			backspace--;
		} else {
			break;
		}
		index--;
	}
	return index;
}

void TwoPointers::BackspaceCompare() {
	cout << "\nBackspace Compare" << endl;
	cout << BackspaceCompare("xy#z", "xzz#") << endl;
  	cout << BackspaceCompare("xy#z", "xyz#") << endl;
  	cout << BackspaceCompare("xp#", "xyz##") << endl;
  	cout << BackspaceCompare("xywrrmp", "xywrrmu#p") << endl;
}

int TwoPointers::ShortestWindowSort(const vector<int>& input) {
	int low = 0;
	int high = input.size() - 1;
	//find first rebel from left
	while(low < int(input.size()) - 1 && input[low] <= input[low+1]) {
		low++;
	}
	if(low == (int)input.size() - 1) {
		return 0; //array is aready sorted
	}
	//find first rebel from right
	while(high > 0 && input[high] >= input[high-1]) {
		high--;
	}

	int subArrayMin = INT32_MAX;
	int subArrayMax = INT32_MIN;

	for(int i = low; i <= high; i++) {
		subArrayMin = min(subArrayMin, input[i]);
		subArrayMax = max(subArrayMax, input[i]);
	}

	while(low > 0 && input[low-1] > subArrayMin) {
		low--;
	}

	while(high < int(input.size()) - 1 && input[high+1] < subArrayMax) {
		high++;
	}
	return high - low + 1;
}

void TwoPointers::ShortestWindowSort() {
	cout << "Shortest Window Sort: " << endl;
	cout << ShortestWindowSort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  	cout << ShortestWindowSort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  	cout << ShortestWindowSort(vector<int>{1, 2, 3}) << endl;
  	cout << ShortestWindowSort(vector<int>{3, 2, 1}) << endl;
}

#include "Subsets.h"

vector<vector<int>> Subsets::FindSubsets(const vector<int>& nums) {
	vector<vector<int>> result;
	result.push_back(vector<int>{});

	for(auto number: nums) {
		for(size_t i = 0; i < result.size(); i++) {
			vector<int> subset{result[i]};
			subset.push_back(number);
			result.push_back(subset);
		}
	}
	return result;
}

void Subsets::FindSubsets() {
	vector<vector<int>> result = FindSubsets(vector<int>{1, 3});
	cout << "Here is the list of subsets: " << endl;
	for (auto vec : result) {
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << endl;
	}

	result = FindSubsets(vector<int>{1, 5, 3});
	cout << "Here is the list of subsets: " << endl;
	for (auto vec : result) {
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << endl;
	}
}
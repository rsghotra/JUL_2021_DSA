#include "Subsets.h"

vector<vector<int>> Subsets::FindSubsets(const vector<int>& nums) {
	vector<vector<int>> subsets;
	subsets.push_back(vector<int>{});

	for(auto number: nums) {
		size_t n = subsets.size();
		for(size_t i = 0; i < n; i++) {
			vector<int> subset{subsets[i]};
			subset.push_back(number);
			subsets.push_back(subset);
		}
	}
	return subsets;
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

vector<vector<int>> Subsets::SubsetsWithDuplicates(vector<int>& nums) {
	//do not forget to sort MAN
	sort(nums.begin(), nums.end());
	vector<vector<int>> subsets;
	subsets.push_back(vector<int>{});
	int startIndex = 0;
	int endIndex = 0;
	for(size_t i = 0; i < nums.size(); i++) {
		startIndex = 0;
		if(i > 0 && nums[i-1] == nums[i]) {
			startIndex = endIndex+1;
		}
		endIndex = subsets.size() - 1;
		for(int j = startIndex; j <= endIndex; j++) {
			vector<int> subset(subsets[j]);
			subset.push_back(nums[i]);
			subsets.push_back(subset);
		}
	}
	return subsets;
}

void Subsets::SubsetsWithDuplicates() {
	vector<int> vec = {1, 3, 3};
	vector<vector<int>> result = SubsetsWithDuplicates(vec);
	cout << "Here is the list of subsets: " << endl;
	for (auto vec : result) {
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << endl;
	}

	vec = {1, 5, 3, 3};
	result = SubsetsWithDuplicates(vec);
	cout << "Here is the list of subsets: " << endl;
	for (auto vec : result) {
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> Subsets::Permutations(const vector<int>& nums) {
	vector<vector<int>> result;
	queue<vector<int>> queue;
	queue.push(vector<int>{});

	for(size_t i = 0; i < nums.size(); i++) {
		for(size_t j = 0; j < queue.size(); j++) {
			vector<int> oldPermutation = queue.front();
			queue.pop();
			
			for(int k = 0; k <= int(oldPermutation.size()); i++) {
				vector<int> newPermutaion(oldPermutation);
				newPermutaion.insert(newPermutaion.begin() + k, nums[i]);
				if(newPermutaion.size() == nums.size()) {
					result.push_back(newPermutaion);
				} else {
					queue.push(newPermutaion);
				}
			}
		}
	}
	return result;
}

void Subsets::Permutations() {
	vector<vector<int>> result = Permutations(vector<int>{1, 3, 5});
  	cout << "Here are all the permutations: " << endl;
	for (auto vec : result) {
		for (auto num : vec) {
		cout << num << " ";
		}
		cout << endl;
	}
}

vector<string> Subsets::PermutationsByChangingCase(const string& str) {
	vector<string> permutaions;
	if(str == "") {
		return permutaions;
	}
	permutaions.push_back(str);
	for(size_t i = 0; i< str.size(); i++) {
		if(isalpha(str[i])) {
			int n = permutaions.size();
			for(int j = 0; j < n; j++) {
				vector<char> chs(permutaions[j].begin(), permutaions[j].end());
				if(islower(chs[i])) {
					chs[i] = toupper(chs[i]);
				} else {
					chs[i] = tolower(chs[i]);
				}
				permutaions.push_back(string(chs.begin(), chs.end()));
			}
		}
	}
	return permutaions;
}

void Subsets::PermutationsByChangingCase() {
	vector<string> result = PermutationsByChangingCase("ad52");
	cout << "String permutations are: ";
	for (auto str : result) {
		cout << str << " ";
	}
	cout << endl;

	result = PermutationsByChangingCase("ab7c");
	cout << "String permutations are: ";
	for (auto str : result) {
		cout << str << " ";
	}
	cout << endl;
}

vector<string> Subsets::GenerateParanthesis(int num) {
	queue<ParanthesisString> queue;
	vector<string> result;
	queue.push({"", 0, 0});
	while(!queue.empty()) {
		ParanthesisString ps = queue.front();
		queue.pop();
		if(ps.openBkt == num && ps.closeBkt == num) {
			result.push_back(ps.str);
		} else {
			if(ps.openBkt < num) {
				queue.push({ps.str+"(", ps.openBkt+1, ps.closeBkt});
			}

			if(ps.openBkt > ps.closeBkt) {
				queue.push({ps.str + ")", ps.openBkt, ps.closeBkt+1});
			}
		}
	}
	return result;
}

void Subsets::GenerateParanthesis() {
	vector<string> result = GenerateParanthesis(2);
	cout << "All combinations of balanced parentheses are: ";
	for (auto str : result) {
		cout << str << " ";
	}
	cout << endl;

	result = GenerateParanthesis(3);
	cout << "All combinations of balanced parentheses are: ";
	for (auto str : result) {
		cout << str << " ";
	}
	cout << endl;
}
unordered_map<string, vector<int>> evalMap = unordered_map<string, vector<int>>();
vector<int> Subsets::EvaluateExpression(const string& str) {
	vector<int> result;
	if(evalMap.find(str) != evalMap.end()) {
		return evalMap[str];
	}
	if(str.find('+') == string::npos && str.find('*') == string::npos && str.find('-') == string::npos) {
		result.push_back(stoi(str));
	} else {
		for(size_t i = 0; i < str.size(); i++) {
			if(!isdigit(str[i])) {
				vector<int> leftParts = EvaluateExpression(str.substr(0, i));
				vector<int> rightParts = EvaluateExpression(str.substr(i+1));
				for(auto part1: leftParts) {
					for(auto part2: rightParts) {
						if(str[i] == '+') {
							result.push_back(part1+part2);
						} else if(str[i] == '-') {	
							result.push_back(part1-part2);
						} else if(str[i] == '*') {	
							result.push_back(part1*part2);
						}
					}
				}
			}
		}
	}
	evalMap[str] = result;
	return result;
}

void Subsets::EvaluateExpression() {
	vector<int> result = EvaluateExpression("1+2*3");
	cout << "Expression evaluations: ";
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	result = EvaluateExpression("2*3-4-5");
	cout << "Expression evaluations: ";
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}

vector<TreeNode*> Subsets::FindUniqueTrees(int start, int end) {
	vector<TreeNode*> result;
	if(start > end) {
		result.push_back(nullptr);
		return result;
	}
	for(int i = start; i<=end; i++) {
		vector<TreeNode*> leftSubtrees = FindUniqueTrees(start, i-1);
		vector<TreeNode*> rightSubtrees = FindUniqueTrees(i+1, end);

		for(auto leftSubtree: leftSubtrees) {
			for(auto rightSubtree: rightSubtrees) {
				TreeNode* root = new TreeNode(i);
				root->left = leftSubtree;
				root->right = rightSubtree;
				result.push_back(root);
			}
		}
	}
	return result;
}

void Subsets::FindUniqueTrees() {
	vector<TreeNode *> result = FindUniqueTrees(1,2);
  	cout << "Total trees: " << result.size() << endl;

  	result = FindUniqueTrees(1,3);
  	cout << "Total trees: " << result.size() << endl;
}


unordered_map<int, int> uniqueMap = unordered_map<int, int>();

int Subsets::CountUniqueTrees(int end) {
	if(uniqueMap.find(end) != uniqueMap.end()) {
		return uniqueMap[end];
	}
	if(end <= 1) return 1;
	int count = 0;
	for(int i = 1; i<=end;i++) {
		int leftTrees = CountUniqueTrees(i-1);
		int rightTrees = CountUniqueTrees(end - i);

		count += (leftTrees * rightTrees);
	}
	uniqueMap[end] = count;
	return count;
}


void Subsets::CountUniqueTrees() {
  	int count = CountUniqueTrees(3);
  	cout << "Total Count trees: " << count;
}
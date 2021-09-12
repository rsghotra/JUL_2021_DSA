#ifndef SUBSETS_H
#define SUBSETS_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

class ParanthesisString {
	public:
		string str;
		int openBkt = 0;
		int closeBkt = 0;
		ParanthesisString(string str, int open, int close) {
			this->str = str;
			this->openBkt = open;
			this->closeBkt = close;
		}
};

class TreeNode {
	public:
	TreeNode* left;
	TreeNode* right;
	int data;
	TreeNode(int data) {
		this->left = 0;
		this->right = 0;
		this->data = data;
	}
};

class Subsets {
	private:
		static vector<vector<int>> FindSubsets(const vector<int>& nums);
		static vector<vector<int>> SubsetsWithDuplicates(vector<int>& nums);
		static vector<vector<int>> Permutations(const vector<int>& nums);
		static vector<string> PermutationsByChangingCase(const string& str);
		static vector<string> GenerateParanthesis(int num);
		static vector<int> EvaluateExpression(const string& input);
		static vector<TreeNode*> FindUniqueTrees(int start, int end);
		static int CountUniqueTrees(int end);
	public:
		static void FindSubsets();
		static void SubsetsWithDuplicates();
		static void Permutations();
		static void PermutationsByChangingCase();
		static void GenerateParanthesis();
		static void EvaluateExpression();
		static void FindUniqueTrees();
		static void CountUniqueTrees();
};


#endif
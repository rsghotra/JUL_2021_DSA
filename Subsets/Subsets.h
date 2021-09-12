#ifndef SUBSETS_H
#define SUBSETS_H
#include<iostream>
#include<vector>
using namespace std;

class Subsets {
	private:
		static vector<vector<int>> FindSubsets(const vector<int>& nums);
	public:
		static void FindSubsets();
};


#endif
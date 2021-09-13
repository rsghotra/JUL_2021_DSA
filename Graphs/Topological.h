#ifndef TOPOLOGICAL_H
#define TOPOLOGICAL_H
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Topological {
	private:
		static vector<int> TopologicalSort(int vertices, const vector<vector<int>>& edges);
		static bool TaskScheduling(int tasks, const vector<vector<int>>& prerequisites);
		static string AlienDictionary(const vector<string>& words);
		static bool ReconstructOriginalSequence(const vector<int>& originalSequence, const vector<vector<int>>& sequences);
		static vector<int> MinimumHeightTree(int nodes, const vector<vector<int>>& edges);
	public:
		static void TopologicalSort();
		static void TaskScheduling();
		static void AlienDictionary();
		static void ReconstructOriginalSequence();
		static void MinimumHeightTree();

};


#endif
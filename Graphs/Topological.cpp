#include "Topological.h"

vector<int> Topological::TopologicalSort(int vertices, const vector<vector<int>>& edges) {
	vector<int> result;
	//a. initiliazation of graph
		//parent to child
	unordered_map<int, vector<int>> graph;
		//grandparent to parent
	unordered_map<int, int> inDegree;

	for(int i = 0; i < vertices; i++) {
		graph[i] = vector<int>{};
		inDegree[i] = 0;
	}

	//b. Build the graph
	for(int i = 0; i < int(edges.size()); i++) {
		int parent = edges[i][0];
		int child = edges[i][1];

		graph[parent].push_back(child);
		inDegree[child]++;
	}

	//c. Source Find
	queue<int> sources;
	for(auto entry: inDegree) {
		if(entry.second == 0) {
			sources.push(entry.first);
		}
	}

	//d. sort
	while(!sources.empty()) {
		int vtx = sources.front();
		sources.pop();
		result.push_back(vtx);
		vector<int> children = graph[vtx];
		for(auto child: children) {
			inDegree[child]--;
			if(inDegree[child] == 0) {
				sources.push(child);
			}
		}
	}

	//e. Assess
	if(int(result.size()) != vertices) {
		return vector<int>();
	}
	return result;
}

void Topological::TopologicalSort() {
	vector<int> result =
    TopologicalSort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                                                   vector<int>{2, 0}, vector<int>{2, 1}});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	result = TopologicalSort(
		5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},
								vector<int>{2, 1}, vector<int>{3, 1}});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	result = TopologicalSort(
		7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3},
								vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1},
								vector<int>{3, 2}, vector<int>{4, 1}});
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}


bool Topological::TaskScheduling(int tasks, const vector<vector<int>>& prerequisites) {
	vector<int> taskSchedule;
	//a. initialization
	unordered_map<int, vector<int>> graph;
	unordered_map<int, int> inDegree;

	for(int i = 0; i < tasks; i++) {
		graph[i] = vector<int>();
		inDegree[i] = 0;
	}

	//b build graph
	for(int i = 0; i < int(prerequisites.size()); i++) {
		int parent = prerequisites[i][0];
		int child = prerequisites[i][1];

		graph[parent].push_back(child);
		inDegree[child]++;
	}

	//c. obtain sources
	queue<int> sources;
	for(auto entry: inDegree) {
		if(entry.second == 0) {
			sources.push(entry.first);
		}
	}

	//d. sort
	while(sources.empty() == false) {
		int vtx = sources.front();
		sources.pop();
		taskSchedule.push_back(vtx);
		vector<int> children = graph[vtx];
		for(auto child: children) {
			inDegree[child]--;
			if(inDegree[child] == 0) {
				sources.push(child);
			}
		}
	}

	//e. check
	if(int(taskSchedule.size()) != tasks) {
		return false;
	}
	return true;
}

void Topological::TaskScheduling() {
	bool result = TaskScheduling(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
	cout << "Tasks execution possible: " << result << endl;

	result = TaskScheduling(
		3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
	cout << "Tasks execution possible: " << result << endl;

	result = TaskScheduling(
		6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
								vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
	cout << "Tasks execution possible: " << result << endl;
}

string Topological::AlienDictionary(const vector<string>& words) {
	string resultString;
	//initialization
	unordered_map<char, vector<char>> graph;
	unordered_map<char, int> inDegree;

	for(auto word: words) {
		for(char ch: word) {
			graph[ch] = vector<char>();
			inDegree[ch] = 0;
		}
	}

	//buildgraph
	for(int i = 0; i < words.size() - 1; i++) {
		string word1 = words[i];
		string word2 = words[i+1];
		for(int j = 0; j < min(word1.size(), word2.size()); j++) {
			char parent = word1[j];
			char child = word2[j];
			if(parent != child) {
				graph[parent].push_back(child);
				inDegree[child]++; //only one rule from a pair;
				break;
			}
		}
	}
	//sources
	queue<char> sources;
	for(auto entry: inDegree) {
		if(entry.second == 0) {
			sources.push(entry.first);
		}
	}

	//sort/ordering
	while(!sources.empty()) {
		char ch = sources.front();
		sources.pop();
		resultString += ch;
		vector<char> children = graph[ch];
		for(auto child: children) {
			inDegree[child]--;
			if(inDegree[child] == 0) {
				sources.push(child);
			}
		}
	}

	//assess what we got
	if(resultString.size() != inDegree.size()) {
		return "";
	}
	return resultString;
}

void Topological::AlienDictionary() {
	string result = AlienDictionary(vector<string>{"ba", "bc", "ac", "cab"});
	cout << "Character order: " << result << endl;

	result = AlienDictionary(vector<string>{"cab", "aaa", "aab"});
	cout << "Character order: " << result << endl;

	result = AlienDictionary(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
	cout << "Character order: " << result << endl;
}

bool Topological::ReconstructOriginalSequence(const vector<int>& originalSequence, const vector<vector<int>>& sequences) {
	//initial
	unordered_map<int, vector<int>> graph;
	unordered_map<int, int> inDegree;
	vector<int> order;
	for(auto sequence: sequences) {
		for(auto ele: sequence) {
			graph[ele] = vector<int>();
			inDegree[ele] = 0;
		}
	}
	//build
	for(int i = 0; i < sequences.size(); i++) {
		for(int j = 0; j < int(sequences[i].size()) - 1; j++) {
			int parent = sequences[i][j];
			int child = sequences[i][j+1];

			graph[parent].push_back(child);
			inDegree[child]++;
		}
	}
	if(inDegree.size() != originalSequence.size()) {
		return false;
	}
	//sources
	queue<int> sources;
	for(auto entry: inDegree) {
		if(entry.second == 0) {
			sources.push(entry.first);
		}
	}
	while(!sources.empty()) {
		if(sources.size() > 1) {
			return false;
		}
		if(originalSequence[order.size()] != sources.front()) {
			return false;
		}
		int vtx = sources.front();
		order.push_back(vtx);
		sources.pop();
		vector<int> children = graph[vtx];
		for(auto child: children) {
			inDegree[child]--;
			if(inDegree[child] == 0) {
				sources.push(child);
			}
		}
	}
	if(order.size() != originalSequence.size()) {
		return false;
	}
	return true;
}

void Topological::ReconstructOriginalSequence() {
	bool result = ReconstructOriginalSequence(
	vector<int>{1, 2, 3, 4},
	vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  	cout << "Can we uniquely construct the sequence: " << result << endl;

  	result = ReconstructOriginalSequence(
	vector<int>{1, 2, 3, 4},
	vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  	cout << "Can we uniquely construct the sequence: " << result << endl;

  	result = ReconstructOriginalSequence(
	vector<int>{3, 1, 4, 2, 5},
	vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  	cout << "Can we uniquely construct the sequence: " << result << endl;
}

vector<int> Topological::MinimumHeightTree(int nodes, const vector<vector<int>>& edges) {
	vector<int> minHeightTreesRootNodes;
	//special case
	if(nodes == 1) {
		minHeightTreesRootNodes.push_back(0);
		return minHeightTreesRootNodes;
	}

	//initialize graph
	unordered_map<int, vector<int>> graph;
	unordered_map<int, int> inDegree;

	for(int i = 0; i < nodes; i++) {
		inDegree[i] = 0;
		graph[i] = vector<int>();
	}

	for(int i = 0; i < edges.size(); i++) {
		int parent = edges[i][0];
		int child = edges[i][1];

		graph[parent].push_back(child);
		graph[child].push_back(parent);

		inDegree[parent]++;
		inDegree[child]++;
	}

	queue<int> leaves;
	for(auto entry: inDegree) {
		if(entry.second == 1) {
			leaves.push(entry.first);
		}
	}
	int currentNodes = nodes;
	while(currentNodes > 2) {
		int leavesSize = leaves.size();
		currentNodes -= leavesSize;
		for(int i = 0; i < leavesSize; i++) {
			int vtx = leaves.front();
			leaves.pop();
			vector<int> children = graph[vtx];
			for(auto child: children) {
				inDegree[child]--;
				if(inDegree[child] == 1) {
					leaves.push(child);
				}
			}
		}
	}
	while(leaves.empty() == false) {
		minHeightTreesRootNodes.push_back(leaves.front());
		leaves.pop();
	}
	return minHeightTreesRootNodes;
}

void Topological::MinimumHeightTree() {
	vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
	vector<int> result = MinimumHeightTree(5, vec);
	cout << "Roots of MHTs: ";
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	vec = {{0, 1}, {0, 2}, {2, 3}};
	result = MinimumHeightTree(4, vec);
	cout << "Roots of MHTs: ";
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	vec = {{0, 1}, {1, 2}, {1, 3}};
	result = MinimumHeightTree(4, vec);
	cout << "Roots of MHTs: ";
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}
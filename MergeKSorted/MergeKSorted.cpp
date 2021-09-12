#include "MergeKSorted.h"

ListNode* MergeKSorted::MergeKSortedLL(const vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, ListValCompare> minHeap;

	for(auto root: lists) {
		if(root != 0) {
			minHeap.push(root);
		}
	}
	ListNode* newHead = 0;
	ListNode* tail = 0;
	while(!minHeap.empty()) {
		ListNode* node = minHeap.top();
		minHeap.pop();
		if(newHead == 0) {
			newHead = tail = node;
		} else {
			tail->next = node;
			tail = tail->next;
		}
		if(node->next) {
			minHeap.push(node->next);
		}
	}
	return newHead;
}

void MergeKSorted::MergeKSortedLL() {
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(6);
	l1->next->next = new ListNode(8);

	ListNode *l2 = new ListNode(3);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(7);

	ListNode *l3 = new ListNode(1);
	l3->next = new ListNode(3);
	l3->next->next = new ListNode(4);

	ListNode *result = MergeKSortedLL(vector<ListNode *>{l1, l2, l3});
	cout << "Here are the elements form the merged list: ";
	while (result != nullptr) {
		cout << result->data << " ";
		result = result->next;
	}
}

int MergeKSorted::KthSmallestFromMSortedArrays(const vector<vector<int>>& lists, int K) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, ValCompare> minHeap;
	for(size_t i = 0; i < lists.size(); i++) {
		if(lists[i].empty() == false) {
			minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
		}
	}
	int count = 0; int result = 0;
	while(minHeap.empty() == false) {
		auto entry = minHeap.top();
		minHeap.pop();
		result = entry.first;
		count++;
		if(count == K) {
			return result;
		}
		entry.second.second++;
		if(int(lists[entry.second.first].size()) > entry.second.second) {
			entry.first = lists[entry.second.first][entry.second.second];
			minHeap.push(entry);
		}
	}
	return result;	
}

void MergeKSorted::KthSmallestFromMSortedArrays() {
	vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  	int result = KthSmallestFromMSortedArrays(lists, 5);
  	cout << "\nKth smallest number is: " << result;
}

pair<int, int> MergeKSorted::SmallestNumberRange(const vector<vector<int>>& lists) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, ValCompare> minHeap;
	int currentMax = INT32_MIN;
	for(size_t i = 0; i < lists.size(); i++) {
		if(!lists[i].empty()) {
			minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
			currentMax = max(currentMax, lists[i][0]);
		}
	}
	int rangeStart = 0;
	int rangeEnd = INT32_MAX;

	while(minHeap.size() == lists.size()) {
		auto entry = minHeap.top();
		minHeap.pop();
		if(rangeEnd - rangeStart > currentMax - entry.first) {
			rangeStart = entry.first;
			rangeEnd = currentMax;
		}
		entry.second.second++;
		if(int(lists[entry.second.first].size()) > entry.second.second) {
			entry.first = lists[entry.second.first][entry.second.second];
			currentMax = max(currentMax, entry.first);
			minHeap.push(entry);
		}
	}
	return make_pair(rangeStart, rangeEnd);
}

void MergeKSorted::SmallestNumberRange() {
	vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  	auto result = SmallestNumberRange(lists);
  	cout << "\nSmallest range is: [" << result.first << ", " << result.second << "]";
}


struct PairCompare {
	bool operator()(const pair<int, int> &x, const pair<int, int>& y) {
		return x.first + x.second > y.first + y.second;
	}
};

vector<pair<int, int>> MergeKSorted::FindKLargestPairs(const vector<int>& list1, const vector<int>& list2, int K) {
	vector<pair<int, int>> minHeap;
	for(size_t i = 0; i < list1.size() && i < size_t(K); i++) {
		for(size_t j = 0; j < list2.size() && j < size_t(K); j++) {
			if(int(minHeap.size()) < K) {
				minHeap.push_back(make_pair(list1[i], list2[j]));
				push_heap(minHeap.begin(), minHeap.end(), PairCompare());
			} else {
				if(list1[i] + list2[j] < minHeap.front().first + minHeap.front().second) {
					break;
				} else {
					pop_heap(minHeap.begin(), minHeap.end(), PairCompare());
					minHeap.pop_back();
					minHeap.push_back(make_pair(list1[i], list2[j]));
					push_heap(minHeap.begin(), minHeap.end(), PairCompare());
				}
			}
		}
	}
	return minHeap;
}


void MergeKSorted::FindKLargestPairs() {
	auto result = FindKLargestPairs({9, 8, 2}, {6, 3, 1}, 3);
	cout << "\nPairs with largest sum are: ";
	for (auto pair : result) {
		cout << "[" << pair.first << ", " << pair.second << "] ";
	}
}
#ifndef MERGEKSORTED_H
#define MERGEKSORTED_H
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class ListNode {
	public:
		int data;
		ListNode* next;
		ListNode(int data) {
			this->data = data;
			this->next = 0;
		}
};

class MergeKSorted {
	private:
		struct ListValCompare {
			bool operator()(const ListNode* x, const ListNode* y) {
				return x->data > y->data;
			}
		};

		struct ValCompare {
			bool operator()(const pair<int, pair<int, int>>& x, const pair<int, pair<int, int>>& y) {
				return x.first > y.first;
			}
		};
		static ListNode* MergeKSortedLL(const vector<ListNode*>& lists);
		static int KthSmallestFromMSortedArrays(const vector<vector<int>>& lists, int K);
		static pair<int, int> SmallestNumberRange(const vector<vector<int>>& lists);
		static vector<pair<int, int>> FindKLargestPairs(const vector<int>& list1, const vector<int>& list2, int K);
	public:
		static void MergeKSortedLL();
		static void KthSmallestFromMSortedArrays();
		static void SmallestNumberRange();
		static void FindKLargestPairs();
};

#endif

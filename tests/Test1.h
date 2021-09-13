#ifndef TEST1_H
#define TEST1_H

#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

struct ListNode {
	ListNode* next;
	int data;
	ListNode(int d) {
		this->data = d;
		this->next = 0;
	}
};

class Test1 {
	private:
		static int MinimumMeetingRooms(vector<vector<int>>& meetings);
		static int MaxCPULoad(vector<vector<int>>& cpu);
		static ListNode* MiddleOfLinkedList(ListNode*);
	public:
		static void MinimumMeetingRooms();
		static void MaxCPULoad();
		static void MiddleOfLinkedList();
};


#endif
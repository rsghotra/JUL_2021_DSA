#include <iostream>
using namespace std;

struct ListNode {
	ListNode *next;
	int data;
	ListNode(int data) {
		this->data = data;
		this->next = 0;
	}
};

ListNode* DetectCycleStart(ListNode*);
int CalculateLength(ListNode*);
int CycleLength(ListNode* head);

bool HasCycle(ListNode *head) {
	ListNode *slow = head;
	ListNode *fast = head;

	while (fast != 0) {
		fast = fast->next;
		if (fast) {
			fast = fast->next;
		}
		slow = slow->next;
		if (slow == fast)
			return true;
	}
	return false;
}

ListNode* DetectCycleStart(ListNode* slow) {
  int length = CycleLength(slow);
  if(length != -1) {
    ListNode* ptr1 = slow;
    ListNode* ptr2 = slow;
    while(length > 0) {
      length--;
      ptr1 = ptr1->next;
    }
    while(ptr1 != ptr2) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    return ptr1;
  }
  return nullptr;
}

int CycleLength(ListNode* head) {
  //detect cycle, then call for calculate length
  ListNode* slow = head;
  ListNode* fast = head;
  while(fast) {
    fast = fast->next;
    if(fast) {
      fast = fast->next;
    }
    slow = slow->next;
    if(slow == fast) {
      return CalculateLength(slow);
    }
  }
  return -1;
}

int CalculateLength(ListNode* slow) {
  ListNode* ptr = slow;
  int length = 0;
  do {
    length++;
    ptr = ptr->next;
  }while(ptr != slow);
  return length;
}

ListNode *CreateCyclicList() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	cout << "LinkedList has cycle: " << HasCycle(head) << endl;

	head->next->next->next->next->next->next = head->next->next;
	cout << "LinkedList has cycle: " << HasCycle(head) << endl;

	head->next->next->next->next->next->next = head->next->next->next;
	cout << "LinkedList has cycle: " << HasCycle(head) << endl;
	return head;
}

int main() {
	ListNode *head = CreateCyclicList();
  int cycleLen = CycleLength(head);
  if(cycleLen == -1) {
    cout << "No cycle detected" << endl;
  } else {
    cout << "Cycle of length of " << cycleLen << " detected." << endl;
  }

  ListNode* startPoint = DetectCycleStart(head);
  cout << "The starting node is: " << startPoint->data << endl;

  return 0;
}

#include<iostream>
using namespace std;

struct ListNode {
    ListNode* next;
    int data;
    ListNode(int data) {
        this->data = data;
        this->next = 0;
    }
};

bool HasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != 0) {
        fast = fast->next;
        if(fast) {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}

int main() {
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
}


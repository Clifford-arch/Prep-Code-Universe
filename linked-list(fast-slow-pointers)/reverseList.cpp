#include <iostream>
using namespace std;

// Node of linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Reverse linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* next = curr->next; // Save next node
        curr->next = prev;           // Reverse link
        prev = curr;                 // Move prev
        curr = next;                 // Move curr
    }

    return prev;
}

// Print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed: ";
    printList(head);

    return 0;
}
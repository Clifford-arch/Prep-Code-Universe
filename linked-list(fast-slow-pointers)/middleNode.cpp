#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Helper function to create a linked list
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* middle = sol.middleNode(head);

    cout << "Middle Node: " << middle->val << endl;

    cout << "List from Middle: ";
    printList(middle);

    return 0;
}
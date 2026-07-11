#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* previous = nullptr;
        ListNode* current = slow;
        while (current != nullptr) {
            ListNode* nextTemp = current->next;
            current->next = previous;
            previous = current;
            current = nextTemp;
        }

        // Merge two halves
        ListNode* first = head;
        ListNode* second = previous;

        while (second->next != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

//linked list from vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    ListNode* head = createList(nums);

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered List:\n";
    printList(head);

    return 0;
}
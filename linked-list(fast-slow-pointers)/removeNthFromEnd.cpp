#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};

ListNode* createList(vector<int> v) {
    if (v.empty()) return nullptr;

    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;

    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }

    return head;
}


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
    int n = 2;

    ListNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.removeNthFromEnd(head, n);

    cout << "After Removal: ";
    printList(head);

    return 0;
}
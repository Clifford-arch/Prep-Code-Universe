#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        for (ListNode* head : lists) {
            while (head != nullptr) {
                values.push_back(head->val);
                head = head->next;
            }
        }

        sort(values.begin(), values.end());

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int value : values) {
            tail->next = new ListNode(value);
            tail = tail->next;
        }

        return dummy.next;
    }
};


ListNode* createList(vector<int> nums) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }

    return dummy.next;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


int main() {
  

    ListNode* l1 = createList({1, 4, 5});
    ListNode* l2 = createList({1, 3, 4});
    ListNode* l3 = createList({2, 6});

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);


    return 0;
}
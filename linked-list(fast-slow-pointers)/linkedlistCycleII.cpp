#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* ptr = head;

                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return nullptr;
    }
};

int main() {
    vector<ListNode*> nodes;
    nodes.push_back(new ListNode(3));
    nodes.push_back(new ListNode(2));
    nodes.push_back(new ListNode(0));
    nodes.push_back(new ListNode(-4));

    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // Create cycle://
    // -4 -> 2 (cycle starts at node with value 2)
    nodes[3]->next = nodes[1];

    Solution obj;
    ListNode* ans = obj.detectCycle(nodes[0]);

    if (ans)
        cout << "Cycle starts at node with value: " << ans->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
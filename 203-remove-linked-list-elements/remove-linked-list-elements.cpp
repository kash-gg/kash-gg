/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                // Remove the node
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        // Save the new head and delete dummy
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

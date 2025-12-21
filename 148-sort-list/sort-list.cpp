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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = getMiddle(head);

        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* rightSorted = sortList(right);

        return merge(left, rightSorted);
    }
    ListNode* getMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;  // Start fast one ahead
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

    ListNode* merge(ListNode* left, ListNode* right) {
    // Create dummy to build result
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    
    // Merge two sorted lists
    while (left && right) {
        if (left->val <= right->val) {
            curr->next = left;
            left = left->next;
        } else {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }
    
    // Attach remaining nodes
    curr->next = left ? left : right;
    
    return dummy->next;
}

};
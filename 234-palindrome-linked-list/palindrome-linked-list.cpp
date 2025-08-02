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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count += 1;
            temp = temp->next;
        }
        ListNode* a = head;
        for (int i = 0; i < count / 2; i++) {
            a = a->next;
        }
        ListNode* curr = a;
        ListNode* prev = NULL;
        ListNode* next = a;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* first = head;
        ListNode* second = prev;
        for (int i = 0; i < count / 2; i++) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
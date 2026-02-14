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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k = k%n;
        if(k==0) return head;

        ListNode* fast = head;
        for(int i = 0;i<k;i++){
            fast = fast -> next;
        }

        ListNode* slow = head;
        while(fast->next){
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode* a = slow -> next;
        slow->next = nullptr;
        fast -> next = head;

        return a;

    }
};
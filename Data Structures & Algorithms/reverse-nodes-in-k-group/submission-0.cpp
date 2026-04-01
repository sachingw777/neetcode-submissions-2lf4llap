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

    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* secondHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        head = secondHead;
        return secondHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        if(k == 0 || k == 1) return head;

        int count = 1;
        ListNode* temp = head;

        while(temp && count < k){
            temp = temp->next;
            count++;
        }

        if(temp == NULL) return head;

        ListNode *secondHead = temp->next;
        temp->next = NULL;
        ListNode *newHead = reverseLL(head);

        ListNode *small = reverseKGroup(secondHead, k);

        head->next = small;
        head = newHead;
        
        return head;
    }
};

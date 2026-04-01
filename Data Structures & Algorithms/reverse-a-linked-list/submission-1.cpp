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
    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL || head -> next == NULL) return head;

    //     ListNode* secondHead = reverseList(head->next);

    //     head->next->next = head;
    //     head->next = NULL;
    //     head = secondHead;

    //     return head;
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
        return head;
    }
};

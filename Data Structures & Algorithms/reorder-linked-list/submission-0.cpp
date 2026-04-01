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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *secondHead = slow->next;
        slow->next = NULL;

        ListNode *prev = NULL, *curr = secondHead, *temp = NULL;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        secondHead = prev;

        ListNode *temp1=head, *temp2 = secondHead, *tail = head;
        while(temp2){
            temp1 = temp1->next;
            tail->next = temp2;
            temp2 = temp2->next;
            tail = tail->next;
            tail->next = temp1;
            tail = tail->next;
        }
    }
};

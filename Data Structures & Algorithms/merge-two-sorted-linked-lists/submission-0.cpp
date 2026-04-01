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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *finalHead = NULL, *finalTail = NULL;
        if(list1->val <= list2->val){
            finalHead = list1;
            finalTail = list1;
            list1 = list1->next;
        }else{
            finalHead = list2;
            finalTail = list2;
            list2 = list2->next;                          
        }

        while(list1 && list2){
            if(list1->val <= list2->val){
                finalTail->next = list1;
                finalTail = finalTail -> next;
                list1 = list1->next;
            }else{
                finalTail->next = list2;
                finalTail = finalTail -> next;
                list2 = list2->next;                          
            }
        }

        if(list1) finalTail->next = list1;
        if(list2) finalTail->next = list2;

        return finalHead;
    }
};

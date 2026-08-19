/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public void reorderList(ListNode head) {

        // 1. Find middle
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2. Split list
        ListNode secondHead = slow.next;
        slow.next = null;

        // 3. Reverse second half
        ListNode current = secondHead;
        ListNode prev = null;

        while(current != null){
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        secondHead = prev;

        // 4. Merge alternately
        ListNode first = head;

        while(secondHead != null){
            ListNode t1 = first.next;
            ListNode t2 = secondHead.next;

            first.next = secondHead;
            secondHead.next = t1;

            first = t1;
            secondHead = t2;
        }
    }
}
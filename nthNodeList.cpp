//problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

//remove nth node from end of linked list

/*SOLUTION*/

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
ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head; //dummy node points to the head

        ListNode* first = dummy;
        ListNode* second = dummy; //two pointers

        /*iterate until nth node*/
        for(int i = 0; i <= n; i++) {
            first = first->next;
        }

        while(first) {
            //move pointers so first reaches end of list;
            first = first->next;
            second = second->next;
        }

        ListNode* removeNode = second->next;
        second->next = second->next->next; //update second's next pointer

        //free mem of the deleted node
        delete removeNode;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead; //return the new list after deletion

    }
};
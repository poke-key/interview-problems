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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;

            for(int i = 0; i < lists.size(); i +=2 ) //incrementing by 2 b/c dealing with pairs 
            {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1,l2));
            }

            lists = mergedLists;
        }
        return lists[0];
    }
private:

    //helper for merging
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 && l2) {
            if(l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;

            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }


        current->next = l1 ? l1 : l2;

        return dummy.next;
        
    }

};
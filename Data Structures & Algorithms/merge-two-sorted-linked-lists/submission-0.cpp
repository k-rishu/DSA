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
        ListNode* curr = new ListNode(0);
        ListNode* result = curr;
        ListNode* pos1 = list1;
        ListNode* pos2 = list2;
        while (pos1 && pos2) {
            if (pos1->val <= pos2->val) {
                curr->next = new ListNode(pos1->val);
                curr = curr->next;
                pos1 = pos1->next;
            }
            else if (pos2->val <= pos1->val) {
                curr->next = new ListNode(pos2->val);
                curr = curr->next;
                pos2 = pos2->next;
            }
        }

        if (pos1 == nullptr && pos2) {
            curr->next = pos2;
            curr = curr->next;
        }

        if (pos2 == nullptr && pos1) {
            curr->next = pos1;
            curr = curr->next;
        }

        return result->next;
    }
};

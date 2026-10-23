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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (head) {
            curr = head->next;
            head->next = prev;
            prev = head;              
            head=curr;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* newHead = slow->next;
        slow->next = nullptr;

        ListNode* reversedList = reverseList(newHead);

        bool flag = true;
        ListNode* result = new ListNode(0);
        ListNode* curr = result;
        while(head && reversedList){
            if(flag){
                curr->next = head;
                curr = curr->next;
                head = head->next;
                flag = !flag;
            }else{
                curr->next = reversedList;
                curr = curr->next;
                reversedList = reversedList->next;
                flag = !flag;
            }
        }
        if(head!=nullptr){
            curr->next = head;
        }
        if(reversedList!=nullptr){
            curr->next = reversedList;
        }
        head = result->next;

    }
};

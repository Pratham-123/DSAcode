Link - https://leetcode.com/problems/reverse-linked-list/


******************************************************SOLUTION************************************************

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextt = NULL;
        
        while(curr!= NULL){
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        return prev;
    }
};

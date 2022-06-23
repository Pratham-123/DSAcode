Link - https://leetcode.com/problems/linked-list-cycle/

class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head == NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next!= NULL)
        {
            slow = slow->next;
            fast = fast -> next ->next;
            
            if(fast == slow) return true;
        }
        return false;
    }
};

Link - https://leetcode.com/problems/palindrome-linked-list/

public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!= NULL && fast->next->next!= NULL )
        {
            slow = slow ->next;
            fast = fast -> next -> next;
        }
        slow-> next = reverse(slow->next);
        slow = slow ->next;
        while(slow != NULL)
        {
            if(head->val != slow->val )
            {
                return false;
            }
            slow = slow->next;
            head = head ->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
       ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head!=NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head= next;
        }
        return pre;
    }
};

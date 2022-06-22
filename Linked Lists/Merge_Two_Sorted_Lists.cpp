Link - https://leetcode.com/problems/merge-two-sorted-lists/


*********************************************************SOLUTION************************************************


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode *dummy = new ListNode(-2);
        ListNode *head = dummy;
        
        while(l1!=NULL && l2!= NULL){
            if(l1->val<l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }
            else{
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        if(l1 != NULL){
            dummy->next = l1;
        }
         
        if(l2!= NULL){
            dummy->next = l2;
        }
       return head->next; 
        
    }
};

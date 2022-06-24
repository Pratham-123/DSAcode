Link - https://leetcode.com/problems/rotate-list/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == NULL || head->next == NULL || k==0){
          return head;
      }
        ListNode* temp = head;
        int count  =1;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%count;
        k = count-k;
        
        while(k--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

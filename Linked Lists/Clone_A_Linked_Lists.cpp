Link - https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Modiyfying the Linked List
        //1->2->3->4->5
        //1->1->2->2->3->3->4->4->5->5
        Node* curr = head;
        while(curr!= NULL){
            Node* temp =curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
        //setting random pointers for new nodes of new Linked Lists
        while(curr!= NULL){
            if(curr->next!= NULL){
                curr->next->random = (curr->random!=NULL)? curr->random->next:NULL;
            }
            curr = curr->next->next;
        }
        Node* orig = head;
        Node* copy = head!= NULL?head->next:NULL;
        Node* temp = copy;
        //Sepearting both the Linked Lists
        while(orig!= NULL){
            orig->next = orig->next->next;
            copy->next = (copy->next!= NULL)?copy->next->next:NULL;
            orig = orig->next;
            copy = copy->next;
        }
        
        return temp;
        
        
        
        
        
        
        
        
    }
};

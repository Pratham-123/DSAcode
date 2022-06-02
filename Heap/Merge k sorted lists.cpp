Problem Statement
Given 'K' sorted linked lists, each list is sorted in increasing order. You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.
Input Format:
The first line of input contains an integer 'T' denoting the number of queries or test cases. 

The first line of each test case consists of an integer 'K' denoting the number of lists.

Next 'K' lines for each test case will have space separated integers and ith line will have elements of the ith linked list separated by a single space and terminated by -1.
Output Format:
For each test case, print a single line containing space-separated denoting the elements of the merged sorted list. The elements of the linked list must be separated by a single space and terminated by -1.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
0 <= K <= 10 ^ 3
0 <= length of lists <= 100
(-10 ^ 9) <= value of list elements <= (10 ^ 9) && value of list elements != -1.

Time limit: 1 sec.
Sample Input 1:
 2
 3
 4 6 8 -1
 2 5 7 -1
 1 9 -1
 2
 2 6 -1
 -5 7 -1
Sample Output 1:
 1 2 4 5 6 7 8 9 -1
 -5 2 6 7 -1
Explanation For Input 1:
For first test case:
First list is: 4 -> 6 -> 8 -> NULL
Second list is: 2 -> 5 -> 7 -> NULL
Third list is: 1 -> 9 -> NULL
The final list would be: 1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL

For second test case:
First list is: 2 -> 6 -> NULL
Second list is: -5 -> 7 -> NULL
The final list would be: -5 -> 2 -> 6 -> 7 -> NULL
Sample Input 2:
 2
 3
 8 9 11 -1
 1 2 -1 
 -1 
 1
 1 5 6 8 10 -1
Sample Output 2:
1 2 8 9 11 -1
1 5 6 8 10 -1
  
  
  ***************************SOLUTION*******************************
  
  /************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

// TC- O(n*klogk) n-number of nodes in linked list n*k = total number of nodes
//SC- O(k)
#include<bits/stdc++.h>
class compare{
    public:
    bool operator()(Node<int>* a, Node<int>* b){
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;
    int k = listArray.size();
    
    if(k==0) return NULL;
    //adding the head of all linked lists to the minHeap
    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minHeap.push(listArray[i]);
        }
    }
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    while(minHeap.size()>0){
        //taking the smallest element from minHeap and making a LL
        Node<int>* top = minHeap.top();
        minHeap.pop();
        //adding the nect element from that LL to the minHeap
        if(top->next!= NULL){
            minHeap.push(top->next);
        }
        //if the head is NULL, we make a new node and initialise it as head
        if(head == NULL){
            head = top;
            tail = top;
        }
        else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

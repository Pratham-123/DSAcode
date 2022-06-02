Problem Statement
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
Input Format :
The first line of input contains an integer T, the number of test cases.

The first line of each test case contains an integer that denotes the value of K.

The next 2*K lines of each test case follow: 
The first line contains an integer ‘N’ denoting the size of the array. 

The second line contains N space-separated integers. 
Output Format :
The first and only line of output contains space-separated elements of the merged and sorted array, as described in the task.
Note :
You don’t have to print anything; it has already been taken care of. Just implement the function. 
Constraints :
1 <= T <= 5
1 <= K <= 5
1 <= N <= 20
-10^5 <= DATA <= 10^5

Time Limit: 1 sec 
Sample Input 1:
1
2
3 
3 5 9 
4 
1 2 3 8   
Sample Output 1:
1 2 3 3 5 8 9 
Explanation Of Sample Input 1:
After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].
Sample Input 2:
1
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 2:
0 1 2 5 6 9 45 78 90 100 234
Explanation Of Sample Input 2 :
After merging the given arrays/lists [1, 5, 9], [45, 90], [2, 6, 78, 100, 234] and [0], the output sorted array will be [0, 1, 2, 5, 6, 9, 45, 78, 90, 100, 234].

    
    ////////////////////////////////////////////////////////SOLUTION///////////////////////////////////////////////////////////////////
    //TC- O(n*klogk) SC-O(k)
#include<bits/stdc++.h>
//creating node class so we can access the 2d index 
    class node{
        public:
        int data;
        int i;
        int j;
        
        node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
    };

class compare{
    public:
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k){
    //    Write your code here.
    vector<int> ans;
    priority_queue<node*, vector<node*>, compare>  minHeap;
    //adding all the first elements from every array into the minHeap
    for(int i=0;i<k;i++){
        node* tmp = new node(arr[i][0], i, 0);
        minHeap.push(tmp);
    }
    
    while(minHeap.size()>0){
        //now pushing elements into ans array 
        node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();
        //this step is to move forward to the next index or next column
        //because we have just added the current index
        int i = tmp->i;
        int j = tmp->j;
        
        if(j+1 < arr[i].size()){
            node* next = new node(arr[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
    
}


//TC- O(n*klogk) SC-O(k)
#include<bits/stdc++.h>
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
    for(int i=0;i<k;i++){
        node* tmp = new node(arr[i][0], i, 0);
        minHeap.push(tmp);
    }
    
    while(minHeap.size()>0){
        node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();
        
        int i = tmp->i;
        int j = tmp->j;
        
        if(j+1 < arr[i].size()){
            node* next = new node(arr[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
    
}

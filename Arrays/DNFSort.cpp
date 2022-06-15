https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>
#include <iostream>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
      cin>>input[i];
    }
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    int start = 0;
    int mid = 0;
    int end = n-1;
    
    while(mid<=end){
        if(input[mid] == 0){
            swap(input[mid++],input[start++]);
        }
        else if(input[mid] == 2){
            swap(input[mid], input[end--]);
        }
        else{
            mid++;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }

    return 0;
}

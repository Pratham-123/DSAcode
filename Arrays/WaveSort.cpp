Link- 

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(int input[],int n){
    
    for(int i=1;i<=n-1;i+=2){
        if(input[i]>input[i-1]){
            swap(input[i], input[i-1]);
        }
        if(input[i]>input[i+1] && i<=n-2){
            swap(input[i], input[i+1]);
        }
    }
}
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
    solve(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}

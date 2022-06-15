Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is V,. A day is record breaking if it satisfies both of the following conditions:

The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.

Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.

Note that the very first day could be a record breaking day!

Please help Isyana find out the number of record breaking days.
  
  
  
  
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
    int count = 0;
    int mx = input[0];
    int i=0;
    
    while(i<n){
        if(i==0&& input[i]>input[i+1]){
            count++;
            i++;
        }
        else if(i==n-1 && input[i]>mx){
            mx = input[i];
            count++;
            i++;
        }
        else{
            if(input[i]>mx && input[i]> input[i+1]){
                mx = input[i];
                count++;
            }
        }
        i++;
    }
    
    cout<<count<<endl;
    return 0;
}

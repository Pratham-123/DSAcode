

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
  int pd = input[1] - input[0];
  //curr is 2 because there will be 2 elements to calculate the diff
  int curr = 2;
  int j =2;
  int ans =2;
  while(j<n){
      //if the difference is equal increase the prev diff(pd)
      if(pd == input[j] - input[j-1]){
          curr++;
      }
      else{
        //if it is not equal, we will update the pd and make curr 2 again
          pd = input[j] - input[j-1];
          curr = 2;
      }
      ans = max(ans, curr);
      j++;
  }
  cout<<ans<<endl;
    return 0;
}

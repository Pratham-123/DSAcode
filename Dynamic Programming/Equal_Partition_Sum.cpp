
#include <bits/stdc++.h>

using namespace std;
int isSubset(int arr[], int n, int sum){
    if(sum==0) return true;
    if(n==0 && sum!=0) return false;
    if(arr[n-1] > sum){
        isSubset(arr, n-1, sum);
    }
    return (isSubset(arr, n-1, sum) || isSubset(arr, n-1, sum - arr[n-1]));
}
bool findPartiion(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum%2 != 0){
        return false;
    }
    return isSubset(arr, n, sum/2);
}
int main()
{
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}


*********************************Memoization************************************************


#include <bits/stdc++.h>

using namespace std;
int isSubset(int arr[], int n, int sum, vector<vector<int>>& dp){
    if(sum==0) return true;
    if(n==0 && sum!=0) return false;
    if(arr[n-1] > sum){
        isSubset(arr, n-1, sum, dp);
    }
    if(dp[n][sum] != -1) return dp[n][sum];
    return dp[n][sum]= (isSubset(arr, n-1, sum, dp) || isSubset(arr, n-1, sum - arr[n-1], dp));
}
bool findPartiion(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum%2 != 0){
        return false;
    }
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    
    return isSubset(arr, n, sum/2, dp);
}
int main()
{
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}

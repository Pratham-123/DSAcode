Link - https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

Recursion

class Solution
{
    public:
    
    int solve(int n, int a[],int curr, int prev)
    {
       if(curr == n) return 0;
       
       int take = 0;
       if(prev == -1 || a[curr] > a[prev]){
           take += 1 + solve(n,a,curr+1, curr);
       }
       int notTake = 0 + solve(n,a, curr+1, prev);
       
        return max(take, notTake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
      int ans = solve(n, a, 0, -1);
      return ans;
    }
};

/////////////////////////////////////////  MEMOIZATION///////////////////////////////////////////////////////

class Solution
{
    public:
    
    int solve(int n, int a[],int curr, int prev, vector<vector<int>>& dp)
    {
       if(curr == n) return 0;
       if(dp[curr][prev+1] != -1){
           return dp[curr][prev+1];
       }
       int take = 0;
       if(prev == -1 || a[curr] > a[prev]){
           take = 1 + solve(n,a,curr+1, curr,dp);
       }
       int notTake = 0 + solve(n,a, curr+1, prev,dp);
       
        return dp[curr][prev+1] =  max(take, notTake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
      int ans = solve(n, a, 0, -1, dp);
      return ans;
    }
};

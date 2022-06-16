Link- https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        
        for(int i=0;i<numRows;i++){
            //because we can see size of every row is i+1
            dp[i].resize(i+1);
            //first and last element ko 1 set kar diya
            
            dp[i][0] = dp[i][i] = 1;
            for(int j= 1;j<i;j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        return dp;
    }
};


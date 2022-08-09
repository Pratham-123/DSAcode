Link - https://practice.geeksforgeeks.org/problems/edit-distance3702/1

  int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int i=0;i<=m;i++) dp[0][i] = i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    //agr same char h toh
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    //agr same nhi h toh, 1 operation add karo pichle minimum mein
                    dp[i][j] = 1+ min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }

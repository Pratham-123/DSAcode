Link - https://www.geeksforgeeks.org/shortest-common-supersequence/


#include <bits/stdc++.h>

using namespace std;

int lcs(char X[], char Y[], int n, int m){
    int arr[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                arr[i][j] = 0;
            }
            
            else if(X[i-1]==Y[j-1]){
                arr[i][j] = arr[i-1][j-1] +1;
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    return arr[n][m];
}
int shortestSuperSequence(char X[], char Y[]){
    int n = strlen(X);
    int m = strlen(Y);
    
    int l = lcs(X,Y,n,m);
    
    return abs(n+m-l);
}

int main()
{
   char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
 
    cout << "Length of the shortest supersequence is "
         << shortestSuperSequence(X, Y) << endl;
 
    return 0;
}

Link - https://www.geeksforgeeks.org/shortest-common-supersequence/

TC- O(n^2)
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






*************************************************ANOTHER METHOD**********************************************

Below is Another Method to solve the above problem. 
A simple analysis yields below simple recursive solution.

Let X[0..m - 1] and Y[0..n - 1] be two 
strings and m and n be respective
lengths.

  if (m == 0) return n;
  if (n == 0) return m;

  // If last characters are same, then 
  // add 1 to result and
  // recur for X[]
  if (X[m - 1] == Y[n - 1])
     return 1 + SCS(X, Y, m - 1, n - 1);

  // Else find shortest of following two
  //  a) Remove last character from X and recur
  //  b) Remove last character from Y and recur
  else 
    return 1 + min( SCS(X, Y, m - 1, n), SCS(X, Y, m, n - 1) );



// A Naive recursive C++ program to find
// length of the shortest supersequence
#include <bits/stdc++.h>
using namespace std;

int superSeq(char* X, char* Y, int m, int n)
{
	if (!m)
		return n;
	if (!n)
		return m;

	if (X[m - 1] == Y[n - 1])
		return 1 + superSeq(X, Y, m - 1, n - 1);

	return 1
		+ min(superSeq(X, Y, m - 1, n),
				superSeq(X, Y, m, n - 1));
}

// Driver Code
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	cout << "Length of the shortest supersequence is "
		<< superSeq(X, Y, strlen(X), strlen(Y));
	return 0;
}


Link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1


public:
void solve(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if(ind == n){
          ans.push_back(sum);
          return;
      }
      solve(ind+1, arr, n, ans, sum + arr[ind]);
      solve(ind+1, arr, n, ans, sum );
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0, arr, N, ans, 0);
        return ans;
    }

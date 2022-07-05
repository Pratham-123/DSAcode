Link - https://www.interviewbit.com/problems/matrix-median/

int Solution::findMedian(vector<vector<int> > &A) {
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            ans.push_back(A[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    int n = ans.size();
    int anss=0;
    if(n%2==0){
        anss = ans[n/2];
    }
   
    return anss;
}

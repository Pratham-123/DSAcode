Link - https://binarysearch.com/problems/Subsequence-Strings

bool solve(string s1, string s2) {
    int n1= s1.length();
    int n2= s2.length();
    int i=0, j=0;

    while(i<=n1 && j<=n2){

        if(s1[i]==s2[j]){
            i++; j++;

        }
        else{
            j++;
        }

    }
    if(i<n1){
        return false;
    }
    else return true;
}

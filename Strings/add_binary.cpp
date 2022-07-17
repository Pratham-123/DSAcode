Link - https://leetcode.com/problems/add-binary/

class Solution
{
public:
    string addBinary(string a, string b)
    {
      string ans = "";
        int sum=0;
        int carry = 0;
        int n1 = a.length(), n2 = b.length();
        int i=n1-1, j = n2-1;
        while(i>= 0 || j>=0){
            sum += carry;
            if(i>=0){
                sum += a[i--]-'0';
            }
            if(j>=0){
                sum += b[j--]-'0';
            }
            if(sum > 1){
                carry =1;
            }
            else{
                carry = 0;
            }
            //if sum is 3, then 1 will be added
            //if sum is 2, then  0 will be added
            sum = sum%2;
            ans += to_string(sum);
            sum=0;
          
        }
        if(carry !=0){
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

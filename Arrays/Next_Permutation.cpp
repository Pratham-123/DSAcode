Link- https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k,l;
        //we check for the breakpoint like for 13542, 3 will be the breakpoint
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]) break;
        }
        //if we dont find any error, we reverse the vector 54321
        if(k<0) reverse(nums.begin(), nums.end());
        else{
            //we will again run the loop from back and if we find an element greater
            //than that at k, we will swap for the next greater element
            for(l=n-1;l>k;l--){
                if(nums[l] > nums[k]){
                    break;
                }
            }
             swap(nums[k],nums[l]);
            //we will reverse the left over string in hope to make it next greater
            //as they were in increasing order from the last
        reverse(nums.begin()+k+1, nums.end());
        }
       
    }
};

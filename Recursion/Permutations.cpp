
Link- https://leetcode.com/problems/permutations/
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
  
  *************************************************************SOLUTION******************************************************************
  
  class Solution {
public:
    void solve(vector<int> nums, vector<vector<int> > &ans, int index){
        //if we have reached till the last rec call, we will just push it in the ans
        if(index>= nums.size()){
            ans.push_back(nums);
        }
        for(int i=index;i<nums.size();i++){
            //we will use swap function to create all permutations
            //first swap will be with itself and then with all the other elements
            swap(nums[index], nums[i]);
            solve(nums, ans, index+1);
            //we will swap it again because 
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int> > ans;
        solve(nums, ans, index);
        return ans;
    }
};

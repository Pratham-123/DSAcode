Link - https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum<0) left++;
                else if(sum>0){
                    right--;
                }
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    int lastLeft = nums[left];
                    int lastRight = nums[right];
                    while(left<right && nums[left] == lastLeft) left++;
                    while(left<right && nums[right] == lastRight) right--;
                }
            }
        }
        return result;
    }
};

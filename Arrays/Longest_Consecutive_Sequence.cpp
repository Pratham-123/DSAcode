Link - https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        int longStreak = 1;
        int currStreak = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                if(nums[i]==nums[i-1]+1)
                {
                    currStreak +=1;
                }
                else{
                    longStreak = max(longStreak, currStreak);
                    currStreak = 1;
                    
                }
            }
        }
        return max(longStreak, currStreak);
    }
};

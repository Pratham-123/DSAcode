Link - https://leetcode.com/problems/two-sum/

// find(): Searches for a particular element and returns the iterator pointing to the element if the element is
//found otherwise it will return the iterator returned by end(). Its time complexity is O(logN) where N is the size of the set.




class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            if(mapp.find(target-nums[i]) != mapp.end()){
                return {mapp[target-nums[i]] , i};
            }
            mapp[nums[i]] = i;
        }
        return {};
    }
};

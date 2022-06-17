Link- https://leetcode.com/problems/merge-sorted-array/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m, j = 0 ;
        while(i<m+n && j<n){
            nums1[i++] = nums2[j++];
        }
        sort(nums1.begin(), nums1.end());
        
    }



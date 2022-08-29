Link- https://leetcode.com/problems/merge-sorted-array/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m, j = 0 ;
        while(i<m+n && j<n){
            nums1[i++] = nums2[j++];
        }
        sort(nums1.begin(), nums1.end());
        
    }

*****************************************************************************************

The idea is to go from the last indexes of both arrays, compare and put elements from either A or B to the final position, which can easily get since we know that A have enough space to store them all and we know size of A and B. Please refer to the comments for details.

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        
        int a=m-1;
        int b=n-1;
        int i=m+n-1;    // calculate the index of the last element of the merged array
        
        // go from the back by A and B and compare and put to the A element which is larger
        while(a>=0 && b>=0){
            if(A[a]>B[b])   A[i--]=A[a--];
            else            A[i--]=B[b--];
        }
        
        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while(b>=0)         A[i--]=B[b--];
    }
};

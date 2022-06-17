Link - https://leetcode.com/problems/rotate-image/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transposing the matrix means first row ko last column bana do and similarly
        for(int i=0;i<n;i++)
        {
            for(int j =0;j< i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
     
        //reversing each row
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

steps
given matrix:
123
456
789

After transpose
147
258
369

After reversing each row
741
852
963
  


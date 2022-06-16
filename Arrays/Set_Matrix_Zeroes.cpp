Link - https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    

    void setZeroes(vector<vector<int>>& matrix) {
      int col = 1, rows = matrix.size(), cols = matrix[0].size();
        //using the first row and first col to keep track if we have a 0 in that row or column  
        for(int i=0;i<rows;i++){
            if(matrix[i][0] == 0) col =0;
            for(int j =1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        //start traversing from the back of matrix
        for(int i= rows-1;i>=0;i--){
            for(int j = cols-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col == 0) matrix[i][0] = 0;
        }
    }
};

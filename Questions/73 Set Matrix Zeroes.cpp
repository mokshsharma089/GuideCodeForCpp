73. Set Matrix Zeroes
Medium

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Approach 1-
TC-O(M*N)
SC-O(M+N)

Code-
void setZeroes(vector<vector<int>>& matrix) {
        int m,n;
        m=matrix.size();
        n=matrix[0].size();
        vector<bool> rows(m,false);
        vector<bool> col(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows[i]=true;
                    col[j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(rows[i]){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(col[i]){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
            }
        }
    }

Approach 2
TC-O(M*N)
SC-O(1)

Approach -
Just use first row and columns as the markers (
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
)
and then traverse the first rowwise and check if this row needs to become 0
and then do same for columns
but dont change values for first column or row before as it may give wrong ans
change the first rows and columns in the very end;

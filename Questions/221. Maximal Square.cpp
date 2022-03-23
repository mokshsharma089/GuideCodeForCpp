221. Maximal Square
Medium
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

eg 1-
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

eg 2-
Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0

TC-O(n*m)
SC-O(n*m)

Algo -
1. fill last row and last column with as it is values
2. start traversing from matrix[n-2][m-2] to matrix[0][0] filling values based on currently filled values in matrix to left, down , diagnol
3. If matrix[i][j]==0
    fill 0 and move ahead
4. if matrix[i][j]==1
    ans at that positon = 1+ min(matrix[i+1][j],matrix[i][j+1],matrix[i+1][j+1])
5. overall result would be square of largest edge

Code -
int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int result=0;
        vector<vector<int>> box(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++){
            int temp =matrix[n-1][i]=='0'?0:1;
            if(temp==1){
                result=1;
            }
            box[n-1][i] = temp;
        }
        for(int i=0;i<n;i++){
            int temp = matrix[i][m-1]=='0'?0:1;
            if(temp==1){
                result=1;
            }
            box[i][m-1] = temp;
        }
        print(box);
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(matrix[i][j]=='1'){
                    int temp;
                    temp=min(box[i][j+1],min(box[i+1][j+1],box[i+1][j]));
                    box[i][j]=1+temp;
                    result=max(result,box[i][j]);
                }
                else{
                    box[i][j]=0;
                }
                print(box);
            }

        }
        return result*result;
    }
    void print(vector<vector<int>> &a){
        cout<<"\n==================================\n";
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                cout<<a[i][j]<<" , ";
            }
            cout<<endl;
        }
        cout<<"\n==================================\n";
    }

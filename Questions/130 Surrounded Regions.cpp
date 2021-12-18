130. Surrounded Regions
Medium
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example-
Input: board = [["X","X","X","X"],
                ["X","O","O","X"],
                ["X","X","O","X"],
                ["X","O","X","X"]]

Output:         [["X","X","X","X"],
                 ["X","X","X","X"],
                 ["X","X","X","X"],
                 ["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border,
which means that any 'O' on the border of the board are not flipped to 'X'.
 Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
 Two cells are connected if they are adjacent cells connected horizontally or vertically.


 ALGORITHM
1. traverse 1st and last row as well as column, call dfs function if we find 'O'.
2. what dfs function would do is convert all adjacent Os to $.
3. traverse the matrix if we get any Os freely convert them to X as if they would have been reachable by boundary Os they would have been converted to $
4. Also flip back any $ we get back to Os

TC - O(N*M),  N=board.size() and M=board[0].size()
SC - O(N*M) due to call stack

Code-
void dfs(vector<vector<char>>& board,int i,int j){
    if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!='O'){
        return;
    }
    board[i][j]='$';
    dfs(board,i+1,j);
    dfs(board,i,j+1);
    dfs(board,i-1,j);
    dfs(board,i,j-1);
}
void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        //first and last column
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1);
            }
        }
        //first and last row
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i);
            }
            if(board[m-1][i]=='O'){
                dfs(board,m-1,i);
            }
        }
        //if now their is any O left in matrix than that is not connected to any O on bondary and can be changed to X
        // Also change $ back to Os
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='$'){
                    board[i][j]='O';
                }

            }
        }

    }

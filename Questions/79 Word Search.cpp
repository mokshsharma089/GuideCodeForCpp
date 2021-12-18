79. Word Search
Given an m x n grid of characters board and a string word,
return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Input: board = [
                ["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "ABCCED"  starts at (0,0) and ends at (2,1) via (0,2),(2,2),and others
Output: true


Input: board = [
                ["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]],
                word = "SEE"
Output: true

Algorithm-
1. traverse entire array whenever get first letter of string in board perform dfs via helper
2. backtracking is important aspect dont forget about it otherwise a problem can occur
(may use an already used character otherwise).

CODE-
bool exist(vector<vector<char>>& board, string word) {
       for(int i=0;i<board.size();i++){
           for(int j=0;j<board[0].size();j++){
               if(board[i][j]==word[0]){
                   if(helper(board,i,j,word,0)==true){
                       return true;
                   }
               }
           }
       }
       return false;

   }
   bool helper(vector<vector<char>>&board,int i,int j,string &word,int k){
       if(i<0 or i>=board.size() or j<0 or j>=board[0].size() ){
           return false;
       }
       if(k>=word.length()){
           return false;
       }
       if(k==word.length()-1 and word[k]==board[i][j]){
           return true;
       }
       bool ans=false;
       if(word[k]==board[i][j]){
       char temp=board[i][j];
       board[i][j]='$';
       ans=ans||helper(board,i+1,j,word,k+1);
       ans=ans||helper(board,i-1,j,word,k+1);
       ans=ans||helper(board,i,j+1,word,k+1);
       ans=ans||helper(board,i,j-1,word,k+1);
       board[i][j]=temp;
       }
       return ans;
   }

TC-O(M*N*K) where M = no of rows and N=no of columns and K= length of words
SC-O(M*N)

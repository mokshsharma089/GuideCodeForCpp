583. Delete Operation for Two Strings
Medium

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.


Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4


Algorithm-
1. Make use of helper function and 2d dp
2. take a pointer i for string a, and pointer j for string b
3. start traversring strings with help of helper function with indecis 0,0
4. if a[i]==b[j] then means no need for deletion, just ask recursion for the solution of subproblem and return that.
    for eg- if a=ea and b=eat then e==e so just find the ans for a=a and b=at and return that solution here also
5. if a[i]!=b[j], then delete a[i] once and find the result with keeping b as it is, and in other case delete b[j] and keep a as it is.
  for eg a=at and b=bt then find ans for a=t,b=bt and a=at,b=t take whatever is minimum
6. add end conditions if any of strings end 

TC- O(N*M)
SC- O(N*M)

Code-
int minDistance(string word1, string word2) {
       vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
       return helper(word1,word2,0,0,dp);
   }
   int helper(string &a, string &b,int i,int j,vector<vector<int>> &dp){
       if(i==a.length() and j==b.length()){
           return 0;//think about this later point
       }
       if(i==a.length()){
           return b.length()-j;
       }
       if(j==b.length()){
           return a.length()-i;
       }
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       int ans=0;
       if(a[i]==b[j]){
           ans=helper(a,b,i+1,j+1,dp);
       }
       else{
           int del1=helper(a,b,i+1,j,dp)+1;
           int del2=helper(a,b,i,j+1,dp)+1;
           ans=min(del1,del2);
       }
       // cout<<"\n at i= "<<i<<" and j= "<<j<<" deletions needed are "<<ans;
       dp[i][j]=ans;
       return ans;
   }

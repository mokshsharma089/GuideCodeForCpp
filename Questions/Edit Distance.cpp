#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Leetcode 72.
//Edit Distance
// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

// You have the following 3 operations permitted on a word:
// 1.Insert a character OR
// 2.Delete a character OR
// 3.Replace a character OR

//Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

//Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// Algorithm To Solve

// 1. Start Traversing from right ends of both strings
// m=length of string 1
// n=length of string 2
// problem starts from EditDistance(S1,S2,m,n)
//
// 2. If last characters of string match { S1[m] == S2[n] } then , no need to do any operation here
// so just give answer of subproblem ie EditDistance(S1,S2,m-1,n-1)
//
// 3. Else{ last characters Dont match } try to perform all three and return min(of 3 possibilities)
//   A. Insert recur for m,n-1 ie EditDistance(S1,S2,m,n-1)+1
//   B. Remove recur for m-1,n ie EditDistance(S1,S2,m-1,n)+1
//   C. Replace recur for m-1,n-1 ie EditDistance(S1,S2,m-1,n-1)+1
//   +1 is becasue an operation is performed here
//   return minmum of 3

// Use DP TO reduce from O(3^n) to O(MN)

// Base Cases
// if any of the string becomes empty then return the length of other string becaouse thats the number of operations needed to edit
// if(m == -1){return n+1} //if s1 is empty then return length of n under consideration
// if(n == -1){return m+1} //if s2 is empty then return length of n under consideration

int helper(string &w1, string &w2,int m,int n,vector<vector<int> > &dp){
    if(m==-1){
        return n+1;
    }
    if(n==-1){
        return m+1;
    }
    // cout<<"calculation for w1's "<<w1[m]<<" and w2's "<<w2[n]<<endl;
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(w1[m]==w2[n]){
        return helper(w1,w2,m-1,n-1,dp);
    }
    int insert=1,replace=1,remove=1,ans;
    insert+=helper(w1,w2,m,n-1,dp);
    replace+=helper(w1,w2,m-1,n-1,dp);
    remove+=helper(w1,w2,m-1,n,dp);
    ans=min(insert,min(replace,remove));
    dp[m][n]=ans;
    return ans;
}
int EditDistance(string word1, string word2){
    int m=word1.length()-1,n=word2.length()-1;
    vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
    return helper(word1,word2,m,n,dp);
}

int main(){
  string a="horse",b="ros";
  cout<<EditDistance(a,b)<<endl;
  return 1;
}

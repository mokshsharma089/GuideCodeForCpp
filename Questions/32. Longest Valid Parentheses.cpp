32. Longest Valid Parentheses
Hard

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.



Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0


Algorithm -
1. traverse from 0 to n-1 idx
  if s[idx]='(', increment countOfOpenBrackets
  else s[idx]=')', increment countOfCloseBrackets
  if countOfCloseBrackets>countOfOpenBrackets set both counts to 0
  else if countOfOpenBrackets=countOfCloseBrackets we have a possible ans, compare with max found till now
2. traverse from n-1 to 0 idx
  if s[idx]='(', increment countOfOpenBrackets
  else s[idx]=')', increment countOfCloseBrackets
  if countOfOpenBrackets>countOfCloseBrackets set both counts to 0 (see here place is switched compared to above loop)
  else if countOfOpenBrackets=countOfCloseBrackets we have a possible ans, compare with max found till now

TC- O(N)
SC-O(1)

Code -
class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,result=0;

        for(int i=0;i<s.length();i++){

            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }

            if(right>left){
                left=0;
                right=0;
            }
            else if(left==right){
                result=max(result,left+right);
            }
        }

        left=0;right=0;
        for(int i=s.length()-1;i>=0;i--){

            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }

            if(left>right){
                left=0;
                right=0;
            }
            else if(left==right){
                result=max(result,left+right);
            }
        }

        return result;
    }
};

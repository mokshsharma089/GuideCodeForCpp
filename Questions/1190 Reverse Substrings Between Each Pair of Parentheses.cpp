1190. Reverse Substrings Between Each Pair of Parentheses

Medium


You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.



Example 1:
Input: s = "(abcd)"
Output: "dcba"

Example 2:
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.


Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.



Algorithm-
1. traverse the original string, and store result in a separate strings
2. there can be three options whilst traversing the string
  a. s[i]=='(' , then push the next index(of res string) to the stack. So we can reverse starting from here when we encounter the corresponding ')'
  b. s[i]==')', then pop the res string index stored when '(' was encountered and reverse the string bw the current index-1 and value from top of stack
  c. s[i]==character bw a to z, just add character to res string and keep updating the resIDX.

TC-O(N)
SC-O(N)

Code-
string reverseParentheses(string s) {
        string res="";
        int resIdx=-1;
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(resIdx+1);
            }
            else if(s[i]==')'){
                int idxAtTop=st.top();
                st.pop();
                reverse(res,idxAtTop,resIdx);
            }
            else{
                resIdx++;
                res+=s[i];
                // cout<<endl<<"At Res idx = "<<resIdx<<" ,char = "<<res[resIdx];
            }
        }
        return res;
    }
    void reverse(string &s,int i,int j){
        if(i>=j){
            return;
        }
        char temp;
        while(i<j){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
    }

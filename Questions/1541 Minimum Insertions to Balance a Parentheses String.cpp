#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <deque>
#define pb push_back
using namespace std;
// Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:
//
// Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
// Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
// In other words, we treat '(' as openning parenthesis and '))' as closing parenthesis.
//
// For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
//
// You can insert the characters '(' and ')' at any position of the string to balance it if needed.
//
// Return the minimum number of insertions needed to make s balanced.
//
//
//
// Example 1:
// Input: s = "(()))"
// Output: 1
// Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching.
// We need to to add one more ')' at the end of the string to be "(())))" which is balanced.
//
// Example 2:
// Input: s = "())"
// Output: 0
// Explanation: The string is already balanced.
//
// Example 3:
// Input: s = "))())("
// Output: 3
// Explanation: Add '(' to match the first '))', Add '))' to match the last '('.
//
// Example 4:
// Input: s = "(((((("
// Output: 12
// Explanation: Add 12 ')' to balance the string.
//
// Example 5:
// Input: s = ")))))))"
// Output: 5
// Explanation: Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes "(((())))))))".
//
//
// Constraints:
// 1 <= s.length <= 10^5
// s consists of '(' and ')' only.

// Algorithm-
// 1.maintain a stack till the traversed string
// 2. if '(' push to the string and move forward
//   else if ')' check if next can be ')'
//     if s[i+1]==')' and stack is empty then add 1 to ans .Eg-  "))" ==> "())"
//     else if s[i+1]==')' and stack is not empty then just move pointer forward and pop from stack.Eg-  "())" ==> "())"
//     else if s[i+1]!=')' and stack is empty then add 2 to ans .Eg-  ")" ==> "())" Or ")(" ==> "())(" now first "(" is balanced and continue forward for last '('
//     else if s[i+1]!=')' and stack is non empty then add 1 to ans .Eg-  "()(" ==> "())("  now "(" is balanced and continue forward for last '('
// 3. when out of loop while stack is not empty add 2 to the answer because we need that many closing brackets;
//
// TC-O(N) for traversing linearly + emptying stack
// SC-O(N) for stack
int minInsertions(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    if(i+1<s.length()){
                        if(s[i+1]==')'){
                            i++;
                            st.pop();
                        }
                        else{
                        ans++;
                        cout<<endl<<"at index "<<i<<" added 1 to answer because ')' found on non empty stack";
                        st.pop();
                    }
                    }
                    else{
                        ans++;
                        cout<<endl<<"at index "<<i<<" added 1 to answer because ')' found on non empty stack";
                        st.pop();
                    }

                }
                else{
                    if(i+1<s.length()){
                        if(s[i+1]==')'){
                            cout<<endl<<"at index "<<i<<" added 1 to answer because '))' found on empty stack";
                            ans+=1;
                            i++;
                            continue;
                        }
                        else{
                        cout<<endl<<"at index "<<i<<" added 2 to answer because ')' found on empty stack";
                        ans+=2;
                    }
                    }
                    else{
                        ans+=2;
                        cout<<endl<<"at index "<<i<<" added 2 to answer because ')' found on  empty stack";
                    }

                }
            }
        }
        while(st.empty()!=true){
            cout<<endl<<" added 2 to answer because stack is not empty";
            ans+=2;
            st.pop();
        }
        return ans;
    }
int main(){
string s=")))))))";
cout<<endl<<minInsertions(s);
  return 1;
}

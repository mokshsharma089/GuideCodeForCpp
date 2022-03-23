22. Generate Parentheses
Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8

Algo -
1. if open<n :
      add '(' to string and call helper for that
2. if open>close :
       add ')' to string and call helper for that

TC- O(2^N)
SC- O(N)

Code -
vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper("",0,0,n,result);
        return result;

    }
    void helper(string s,int open, int close, int n, vector<string> &result){
        if(open==close and s.length()==2*n){
            result.push_back(s);
            cout<<"\n ------ "<<s;
            return;
        }
        if(open<n){
            string add_opening_brace=s+'(';
            helper(add_opening_brace,open+1,close,n,result);
        }

        if(open>close){
            string add_closing_brace=s+')';
            helper(add_closing_brace,open,close+1,n,result);
        }
    }

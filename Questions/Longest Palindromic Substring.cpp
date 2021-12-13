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
// Q5 Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.
//
//
//
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
// Input: s = "cbbd"
// Output: "bb"
//
// Example 3:
// Input: s = "a"
// Output: "a"
//
// Example 4:
// Input: s = "ac"
// Output: "a"
//
// algorithm
// go about every character from i,i and i,i+1
// and keep expanding from centre to outside
// if "aba" is palindromic then "xabax" is also a palindromic
// we take i,i for palindromes such as "aba" or "b"
// we take i,i+1 for palindromes such as "abba" or "cc"
// to check palindrome start checking we are in valid constraints and if s[l]==s[r]
// if yes then keep moving outwards and checking further
// if no then calculate and return the indexes for left and right and the max length possible
// in the outer keep a check for max, and keep updating if we get max;


//TC-O(N^2)
//SC-O(1)
pair<int,pair<int,int> > expandingAroundCenter(string&s, int l, int r){
    while(l>=0 and r<s.length() and s[l]==s[r]){
        l--;
        r++;
    }
    int sizeOfPalindromeFound=r-l-1;
    int left=l+1;//+1 because we have to move in each direction one extra step before being thrown out of the loop
    int right=r-1;//-1 /+1 because we have to move in each direction one extra step before being thrown out of the loop
    return make_pair(sizeOfPalindromeFound,make_pair(left,right));
}
string longestPalindrome(string s) {
        int best_start,best_end;
        int len=0;
        for(int i=0;i<s.length();i++){
            pair<int,pair<int,int> > l1=expandingAroundCenter(s,i,i);
            pair<int,pair<int,int> > l2=expandingAroundCenter(s,i,i+1);
            if(l1.first>l2.first){
                if(len<l1.first){
                    best_start=l1.second.first;
                    best_end=l1.second.second;
                    len=l1.first;
                }
            }
            else{
                if(len<l2.first){
                    best_start=l2.second.first;
                    best_end=l2.second.second;
                    len=l2.first;
                }
            }
        }
        string ans="";
        // cout<<" best start "<<best_start<<" best end"<<best_end;
        for(int i=best_start;i<=best_end;i++){
            ans+=s[i];
        }
        return ans;
    }

int main(){

  string s="abbbbbbbabbbbadabbbbbbbabbbba";
  cout<<endl<<longestPalindrome(s);//ans=bbbbadabbbb
  return 1;
}

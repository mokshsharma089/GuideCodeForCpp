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
// Leetcode 409
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that
// can be built with those letters.
//
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
//
// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
//
// Example 2:
// Input: s = "a"
// Output: 1
//
// Example 3:
// Input: s = "bb"
// Output: 2
//
// Constraints:
// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only

// ALGO
// traverse the string linearly
// maintain a hashmap to maintain the frequency of characters only till we have traversed
// check for every char in hashmap
//   1. if count is even then take them all in consideration for palindrome and add frequency to tempLength
//   2. if count is odd and we currently dont have a middle in our palindrom add frequncy to tempLength
//   3. if count is odd and we have already taken some char as middle then add 'frequency-1' to tempLength because we only take even count of chars in consideration
// store max value of tempLength and return that

// TC-O(N) as O(52*N) is linear
// SC-O(1) as we take constant space making a hashmap of length 52 at max;

int longestPalindrome(string s) {
        unordered_map<char,int> ch;
        int MaxLength=0;
        bool hasGotMiddle=false;
        for(int i=0;i<s.length();i++){
            hasGotMiddle=false;
            int tempLength=0;
            ch[s[i]]++;
            for(auto a:ch){
                if(a.second%2==0){
                    tempLength+=a.second;
                }
                else if(a.second%2==1 and !hasGotMiddle){
                    tempLength+=a.second;
                    hasGotMiddle=true;
                }
                else if(a.second%2==1 and hasGotMiddle){
                    tempLength+=a.second-1;
                }
            }
            MaxLength=max(tempLength,MaxLength);
            cout<<"At index "<<i<<" till char "<<s[i]<<" Temp Length is "<<tempLength<<" MaxLength gotten is "<<MaxLength<<endl;
        }
        return MaxLength;
    }
int main(){
  string s="abccccdd";
  cout<<endl<<longestPalindrome(s);
  return 1;
}

// OP
// At index 0 till char a Temp Length is 1 MaxLength gotten is 1
// At index 1 till char b Temp Length is 1 MaxLength gotten is 1
// At index 2 till char c Temp Length is 1 MaxLength gotten is 1
// At index 3 till char c Temp Length is 3 MaxLength gotten is 3
// At index 4 till char c Temp Length is 3 MaxLength gotten is 3
// At index 5 till char c Temp Length is 5 MaxLength gotten is 5
// At index 6 till char d Temp Length is 5 MaxLength gotten is 5
// At index 7 till char d Temp Length is 7 MaxLength gotten is 7
// 7

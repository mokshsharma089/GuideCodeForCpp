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
// 49. Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
//
//
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Example 2:
// Input: strs = [""]
// Output: [[""]]
//
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Way 1: gives TLE in last 4 test cases works for 111/115 my way
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<int> used(strs.size(),0);
        vector<string> temp;
        if(strs.size()==1){
            temp.push_back(strs[0]);
            result.push_back(temp);
            return result;
        }
        for(int i=0;i<strs.size();i++){
            if(used[i]==1){
                continue;
            }
            string a=strs[i];
            vector<int> ch(26,0);
            temp.clear();
            temp.push_back(a);
            for(int k=0;k<a.length();k++){
                int idx=a[k]-'a';
                ch[idx]++;
            }
            for(int j=i+1;j<strs.size();j++){
                if(used[j]==1){
                    continue;
                }
                if(a.length()==strs[j].length() and checkAnagram(strs[j],ch)){
                    temp.push_back(strs[j]);
                    used[j]=1;
                }
            }
            used[i]=1;
            result.push_back(temp);
        }
        return result;
    }
    bool checkAnagram(string &b,vector<int> alphabet){
        for(int i=0;i<b.length();i++){
            alphabet[b[i]-'a']--;
            if(alphabet[b[i]-'a']<0){
                return false;
            }
        }
        for(int i=0;i<alphabet.size();i++){
            if(alphabet[i]!=0){
                return false;
            }
        }
        return true;
    }
// Way 2 passes all test codes
// TC-O(nklog(k)) n is the number of strings in arr and k is the length of max strings
// SC-O(n) for unordered_map

// Algo-
// Maintain a hashmap for sorted string.
// hint sorted version of all anagrams is same
// traverse the map at the end and push out value into result
vector<vector<string>> groupAnagrams(vector<string>& strs) {
            if(strs.size()==1){
                vector<vector<string>> a;
                vector<string> b;
                b.push_back(strs[0]);
                a.push_back(b);
                return a;
            }
            unordered_map<string,vector<string>> map;
            for(int i=0;i<strs.size();i++){
                string temp=strs[i];
                sort(strs[i].begin(),strs[i].end());
                map[strs[i]].push_back(temp);
            }
            vector<vector<string>> result;
            for(auto a:map){
                result.push_back(a.second);
            }
            return result;
        }
int main(){


  return 1;
}

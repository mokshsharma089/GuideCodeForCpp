#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;


// Leetcode 767.
//Reorganize String
// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
//
// If possible, output any possible result.  If not possible, return the empty string.
//
// Example 1:
//
// Input: S = "aab"
// Output: "aba"
// Example 2:
//
// Input: S = "aaab"
// Output: ""


//Algorithm
// Greedy approach using max heap and hashmap

// first store all characters and its occurences in a hashmap
// now what we will do is take the 2 chars occuring most in string and try to arrange them one by one like abababab
// where a is the most occuring character and b is the second most occuring character
// for this make use of max heap
//int the end (when heap only contains one character) check if the unused frequency(not yet added in result string) is less than or equal to 1
//because if more than one than result would be false or "" as now we would have to place them together
string reorganizeString(string S) {
        string ans="";
        priority_queue<pair<int,char> > pq;
        unordered_map<char,int> map;
        for(int i=0;i<S.length();i++){
            map[S[i]]++;
        }
        for(auto p:map){
            // cout<<endl<<"char "<<p.first<<" && frequency "<<p.second;
            pq.push(make_pair(p.second,p.first));
        }
        while(pq.size()>=2){
            pair<int,char> Fi,Se;//represents First and second respectilvely which means character with most and second most unused frequesncy
            Fi=pq.top();
            pq.pop();
            Se=pq.top();
            pq.pop();
            ans+=Fi.second;
            ans+=Se.second;
            Fi.first--;
            Se.first--;
            if(Fi.first>0){
                pq.push(Fi);
            }
            if(Se.first>0){
                pq.push(Se);
            }
        }
        while(!pq.empty()){
            pair<int,char> tp=pq.top();
            pq.pop();
            if(tp.first>1){
                return "";
            }
            ans+=tp.second;
        }
        return ans;
    }
int main(){
  string str;
  cin>>str;
  cout<<"\nThe Output is \n"<<reorganizeString(str)<<endl;
  return 1;
}

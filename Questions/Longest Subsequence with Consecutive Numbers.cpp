Problem - Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Input Format
First line contains single integer n.
Second line contains n integers Ai.

Constraints
1<=n<=1e5 1<=Ai<=1e6

Output Format
Single line containing single integer

Sample Input
6
100 4 200 1 3 2
Sample Output
4

Algo-
1. maintain a hashmap for every unique element in array with initial value as false
2. start traversing Array
    if value has been visited in some other subsequence - skip and move to next value
    else value has not been visited in some other subsequence - maintain a count and keep going forward from this number increasing count and marking newly visited nodes as marked. Similarly go backwards.

Basic intuition
if encounter a number, traverse forwards(number+1,number+2,.....) and backwards(number-1,number-2,...) till we keep finding elements in hashmap

Code-
#include<bits/stdc++.h>
using namespace std;
int countLengthOfLongestSubsequenceWithConsequtiveNumbers(vector<int> vec){
     unordered_map<int,bool> m;
     int ans=0;
     for(int i=0;i<vec.size();i++){
          m[vec[i]]=false;
     }
     for(int i=0;i<vec.size();i++){
          if(m[vec[i]]==true){
               //already visited, part of some subsequence, move on
               continue;
          }
          else{
               m[vec[i]]=true;
               int curr=1;
               int j=vec[i];
               //go forward
               while(m.count(++j)!=0){
                    curr++;
                    m[j]=true;
               }
               j=vec[i];
               //go backwards
               while(m.count(--j)!=0){
                    curr++;
                    m[j]=true;
               }
               ans=max(ans,curr);
          }
     }
     return ans;
}
int main(){
     int ans,i,n,temp;

     cin>>n;
     vector<int> vec;
     for(i=0;i<n;i++){
          cin>>temp;
          vec.push_back(temp);
     }
     ans=countLengthOfLongestSubsequenceWithConsequtiveNumbers(vec);
     cout<<ans;
     return 0;
}

Time complexity - O(N)
Space complexity - O(N)

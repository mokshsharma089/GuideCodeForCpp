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
void reverseInGroupsOfK(vector<int> &v,int k){
  int start=0;
  int end=k-1;
  int temp;
  int i,j;
  while(end<v.size()){
    i=start;
    j=end;
    while(i<j){
      temp=v[i];
      v[i]=v[j];
      v[j]=temp;
      i++;
      j--;
    }
    start=end+1;
    end+=k;
  }
  if(start<v.size()){
    i=start;
    j=v.size()-1;
    while(i<j){
      temp=v[i];
      v[i]=v[j];
      v[j]=temp;
      i++;
      j--;
    }
  }

}
int main(){
  int n,temp,k;
  vector<int> a;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    a.pb(temp);
  }
  cin>>k;
  cout<<endl<<"-------------Before transformation-----------------";
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ,";
  }
  reverseInGroupsOfK(a,k);
  cout<<endl<<"-------------After transformation-----------------";
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ,";
  }
  return 1;
}

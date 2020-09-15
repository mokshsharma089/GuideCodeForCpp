#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
#define pb push_back
using namespace std;
bool cmp2ndAsc(pair<int,int> a,pair<int,int> b){
  if(a.second < b.second){
    return true;
  }
  return false;
}
bool cmp2ndDesc(pair<int,int> a,pair<int,int> b){
  if(a.second > b.second){
    return true;
  }
  return false;
}
bool CmpBasedOn2ndDescIfSameCmpBasedOnFirstAsc(pair<int,int> a,pair<int,int> b){
  if(a.second>b.second){
    return true;
  }
  else if(a.second==b.second){
    if(a.first < b.first){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}
int main(){
  //1.
  //int in maps or unordered_map is always initiated with 0
  // map<char,int> map;
  // string s="moksh sharma will be selected for nagarro and will have a great career";
  // for(auto a:s){
  //   map[a]++;
  // }
  // cout<<endl;
  // int j=1;
  // for(auto a:map){
  //   cout<<j<<" "<<a.first<<" -> "<<a.second<<endl;
  //   j++;
  // }
  // // sort(map.begin(),map.end());
  // cout<<endl<<"Not in String :-"<<endl;
  // for(char i='a';i<='z';i++){
  //   if(map.count(i)==0){
  //     cout<<j<<" "<<i<<endl;
  //     j++;
  //   }
  // }


  //2.
  // unordered_map<string,int> map;
  // string s="aaa HGa aba HGaba absa geeks for Geeks geeks for";
  // string tempStr="";
  // for(int i=0;s[i]!='\0';i++){
  //   if(s[i]!=' '){
  //     tempStr+=s[i];
  //   }
  //   else{
  //     map[tempStr]++;
  //     tempStr="";
  //   }
  // }
  // map[tempStr]++;
  // int j=1;
  // cout<<endl;
  // for(auto a:map){
  //   cout<<j<<" "<<a.first<<" -> "<<a.second<<endl;
  //   j++;
  // }
  // vector<pair<int,string> > vec;
  // for(auto a:map){
  //   vec.push_back(make_pair(a.second,a.first));
  // }
  // sort(vec.begin(),vec.end());
  // j=1;
  // for(auto a:vec){
  //   cout<<j<<" "<<a.first<<" -> "<<a.second<<endl;
  //   j++;
  // }


  //3.
  // vector<pair<int,float> > vec;
  // for(int i=0;i<10;i++){
  //   int a=random()%20+1;
  //   int b=random()%20+21;
  //   vec.push_back(make_pair(a,b));
  // }
  // int j=1;
  // cout<<endl<<"Before Sorting - "<<endl;
  // for(auto a:vec){
  //   cout<<j<<". "<<a.first<<" & "<<a.second<<endl;
  //   j++;
  // }
  //sort(vec.begin(),vec.end(), greater<pair<int,int> >() ); sorts based on first value of pair in descending order
  //sort(vec.begin(),vec.end(),less<pair<int,int> >() );  sorts based on first value of pair in ascending order ,does so without less<int> etc
  //sort(vec.begin(),vec.end(),cmp2ndAsc); sorts based on second value of pair in ascending order See how we didnt have to write () after function name
  //sort(vec.begin(),vec.end(),cmp2ndDesc); sorts based on second value of pair in Descending order See how we didnt have to write () after function name
  //sort(vec.begin(),vec.end(),CmpBasedOn2ndDescIfSameCmpBasedOnFirstAsc); custom comparator where first criteria is 2nd value in descending order, if 2nd pair value is same then criteria is 1st pair value in ascending
  // cout<<endl<<"after Sorting - "<<endl;
  // j=1;
  // for(auto a:vec){
  //   cout<<j<<". "<<a.first<<" & "<<a.second<<endl;
  //   j++;
  // }

  // 4.
  //by default it is a max_heap ,use greater<int> in order to make a min_heap
  priority_queue<int,vector<int>,greater<int> > pq;


  return 1;
}

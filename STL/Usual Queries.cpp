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
//used in vectors
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
//used in Heap or priority_queue
//remember oppposite signs ,(> for min_heap)  and (< for max_heap)
class Compare1 {
public:
	bool operator()(int a, int b) {
		return a < b;
    //less than sign for max heap
	}
};
class Compare2 {
public:
	bool operator()(int a, int b) {
		return a > b;
    //greater than sign for min heap
	}
};
//max Heap based on the distance from origin
class ComparePointsDistanceFromOrigin {
public:
	bool operator()(vector<int> &a, vector<int> &b) {
		int x = a[0] * a[0] + a[1] * a[1];
		int y = b[0] * b[0] + b[1] * b[1];

		return x < y;
    //less than sign for max heap
	}
};
int main(){
  //1.
  //int in maps or unordered_map is always initiated with 0
  map<char,int> map;
  string s="are bhai kya code ahi yeh to mast ekdum mast ekdum";
  for(auto a:s){
    map[a]++;
  }
  cout<<endl;
  int j=1;
  for(auto a:map){
    cout<<j<<" "<<a.first<<" -> "<<a.second<<endl;
    j++;
  }
  // sort(map.begin(),map.end());
  cout<<endl<<"Not in String :-"<<endl;
  for(char i='a';i<='z';i++){
    if(map.count(i)==0){
      cout<<j<<" "<<i<<endl;
      j++;
    }
  }


  //2.
  unordered_map<string,int> map;
  string s="aaa HGa aba HGaba absa geeks for Geeks geeks for";
  string tempStr="";
  for(int i=0;s[i]!='\0';i++){
    if(s[i]!=' '){
      tempStr+=s[i];
    }
    else{
      map[tempStr]++;
      tempStr="";
    }
  }
  map[tempStr]++;
  int j=1;
  cout<<endl;
  for(auto a:map){
    cout<<j<<" "<<a.first<<" -> "<<a.second<<endl;
    j++;
  }
  vector<pair<int,string> > vec;
  for(auto a:map){
    vec.push_back(make_pair(a.second,a.first));
  }
  sort(vec.begin(),vec.end());
  j=1;
  for(auto a:vec){
    cout<<j<<" "<<a.first<<" -> "<<a.second<<endl;
    j++;
  }


  //3.
  vector<pair<int,float> > vec;
  for(int i=0;i<10;i++){
    int a=random()%20+1;
    int b=random()%20+21;
    vec.push_back(make_pair(a,b));
  }
  int j=1;
  cout<<endl<<"Before Sorting - "<<endl;
  for(auto a:vec){
    cout<<j<<". "<<a.first<<" & "<<a.second<<endl;
    j++;
  }
  sort(vec.begin(),vec.end(), greater<pair<int,int> >() ); //sorts based on first value of pair in descending order
  sort(vec.begin(),vec.end(),less<pair<int,int> >() );  //sorts based on first value of pair in ascending order ,does so without less<int> etc
  sort(vec.begin(),vec.end(),cmp2ndAsc); //sorts based on second value of pair in ascending order See how we didnt have to write () after function name
  sort(vec.begin(),vec.end(),cmp2ndDesc); //sorts based on second value of pair in Descending order See how we didnt have to write () after function name
  sort(vec.begin(),vec.end(),CmpBasedOn2ndDescIfSameCmpBasedOnFirstAsc); //custom comparator where first criteria is 2nd value in descending order, if 2nd pair value is same then criteria is 1st pair value in ascending
  cout<<endl<<"after Sorting - "<<endl;
  j=1;
  for(auto a:vec){
    cout<<j<<". "<<a.first<<" & "<<a.second<<endl;
    j++;
  }

  // 4.
  //by default it is a max_heap ,use greater<int> in order to make a min_heap
  priority_queue<int, vector<int> > pq; //max_heap
	pq.push(45);
	pq.push(5);
	pq.push(43);
	pq.push(15);
	pq.push(89);
  cout<<endl<<"max Heap"<<endl;
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
  cout<<endl<<"min Heap"<<endl;
  priority_queue<int,vector<int>,greater<int> > pq; //min_heap
  pq.push(45);
	pq.push(5);
	pq.push(43);
	pq.push(15);
	pq.push(89);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

  // Compare p;
	// cout << p(1, 2) << endl;
	// Compare c;
	// c(45, 15);

  //Custom Comparator for max Heap return a<b
  priority_queue<int, vector<int>, Compare1> pq;
	pq.push(45);
	pq.push(5);
	pq.push(43);
	pq.push(15);
	pq.push(89);

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

  //Custom Comparator for min Heap return a>b
  priority_queue<int, vector<int>, Compare2> pq;
	pq.push(45);
	pq.push(5);
	pq.push(43);
	pq.push(15);
	pq.push(89);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

  return 1;
}

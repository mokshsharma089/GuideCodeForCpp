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
void show(deque<int> d){
  cout<<endl<<"--------Show Called----------"<<endl;
  for(int i=0;i<d.size();i++){
    cout<<d[i]<<" , ";
    //can also usr d.at(i)
  }
}
// DEQUEs are similar to vectors, but are more efficient in case of insertion and deletion of elements
//lists are similar but we cant use d[i] or d.at(i) in lists
//in deque we can access index wise
int main(){
  deque<int> d;
  //can push and pop from front and back
  d.push_front(12);//adds at front
  d.push_front(34);//adds at front
  d.push_front(45);//adds at front
  d.push_front(77);//adds at front
  d.push_back(112);//adds at back
  d.push_back(4007);//adds at back
  d.push_back(9899);//adds at back
  show(d);//77 , 45 , 34 , 12 , 112 , 4007 , 9899 ,
  d.pop_back();//removes 9899
  show(d);//77 , 45 , 34 , 12 , 112 , 4007 ,
  d.pop_front();//removes 77
  show(d);// 45 , 34 , 12 , 112 , 4007 ,
  d[2]=9090909;
  show(d);//45 , 34 , 9090909 , 112 , 4007 , %

  //how to sort a deque
  sort(d.begin(),d.end());
  show(d);//34 , 45 , 112 , 4007 , 9090909 ,
  sort(d.begin(),d.end(),greater<int>());
  show(d);//9090909 , 4007 , 112 , 45 , 34 ,

  //can use erase(iterator) to remove any element in deque

  //how to check if element appears in deque
  //67 value is being found in deque, if more than one exists returns address of 1st
  //if no 67 then return d.end()
  auto a=find(d.begin(),d.end(),67);
  cout<<endl<<"Does 67 appear in deque ? "<<(a!=d.end());//false
  return 1;
}

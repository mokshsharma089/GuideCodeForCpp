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
#define pb push_back
using namespace std;
int main(){
   queue<int> q;
   q.push(99);
   q.push(10);
   q.push(45);
   cout<<endl<<"No of elements in QUEUE are - "<<q.size()<<endl;
   while(!q.empty()){
     cout<<q.front()<<" ,";
     q.pop();
   }
   return 1;
}
/*
OP

No of elements in QUEUE are - 3
99 ,10 ,45 ,
*/

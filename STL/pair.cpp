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
// present in <utility> header
// used to store two heterogeneous data types together in a single unit
int main(){
  pair<int, string>a;
   a=make_pair(1,"Moksh");
  cout<<endl<<a.first<<" , "<<a.second;
  pair<string, string> b;
  cout<<endl<<b.first<<" , "<<b.second;
  b.first="2";
  b.second="Sharma";
  cout<<endl<<b.first<<" , "<<b.second;
  pair<int,int> c(34,56);
  cout<<endl<<c.first<<" , "<<c.second;

  // == and != check for both values
  pair<int,int> x(10,12),y(10,12),z(1,10),m(10,15),n(9,12);
  cout<<endl<<"__________Logical Operators__________";
  cout<<endl<<"(10,12)==(10,12) - "<<(x==y);//true
  cout<<endl<<"(10,12)==(1,10) - "<<(x==z);//false
  cout<<endl<<"(10,12)!=(10,12) - "<<(x!=y);//false
  cout<<endl<<"(10,12)==(1,10) - "<<(x!=z);//true
  cout<<endl<<"(10,12)>=(10,12) - "<<(x>=y);//true
  cout<<endl<<"(10,12)<(10,15) - "<<(x<m);//false
  cout<<endl<<"(10,12)>(9,12) - "<<(x>n);//true
  cout<<endl<<"(1,12)<=(10,12) - "<<(make_pair(1,12)<=make_pair(10,12));//true
  cout<<endl<<"(1,12)>=(10,12) - "<<(make_pair(1,12)>=make_pair(10,12));//false
  return 1;
}
/*
OP

1 , Moksh
 ,
2 , Sharma
34 , 56
__________Logical Operators__________
(10,12)==(10,12) - 1
(10,12)==(1,10) - 0
(10,12)!=(10,12) - 0
(10,12)==(1,10) - 1
(10,12)>=(10,12) - 1
(10,12)<(10,15) - 1
(10,12)>(9,12) - 1
(1,12)<=(10,12) - 1
(1,12)>=(10,12) - 0
*/

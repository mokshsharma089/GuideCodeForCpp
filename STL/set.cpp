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

// Properties:
// 1. The set stores the elements in sorted order.
// 2. All the elements in a set have unique values.
// 3. The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
// 4. Sets follow the Binary search tree implementation.
// 5. The values in a set are unindexed.

// To store the elements in an unsorted(random) order,  unordered_set() can be used.

// set<datatype, greater<datatype>> setname; is used for storing values in a set in descending order.

// Set is implemented as a balanced tree structure that is why it is possible to maintain order between the elements (by specific tree traversal).
// The time complexity of set operations is O(log n) while for unordered_set, it is O(1).
int main(){
  set<int> s;
  unordered_set<int> us;
  s.insert(13);
  s.insert(3);
  s.insert(98);
  s.insert(546);
  s.insert(3);

  us.insert(13);
  us.insert(3);
  us.insert(98);
  us.insert(546);
  us.insert(3);

  cout<<endl<<"-------Display of set------"<<endl;
  for(auto a:s){
    cout<<a<<", ";
  }
  cout<<endl<<"-------Display of unordered_set------"<<endl;
  for(auto a:us){
    cout<<a<<", ";
  }

  cout<<endl<<"is set empty? "<<s.empty();

  cout<<endl<<"No of elements in sets - "<<s.size();

  //how to check if element is present in set
  // find(ele) return iterator to the element and if not present returns set.end()
  // can also use s.count(g) which will return 1 if present 0 otherwise
  if(s.find(19)!=s.end()){
    cout<<endl<<"Value is present";
  }
  else{
    cout<<endl<<"Absent";
  }
  //Absent
  s.insert(19);
  if(s.find(19)!=s.end()){
    cout<<endl<<"Value is present";
  }
  else{
    cout<<endl<<"Absent";
  }
  //Value is present

  // how to remove any value from the set
  // use erase(g)
  //no error if value is not present
  us.erase(1787);
  cout<<endl<<"-------Display of unordered_set------"<<endl;
  for(auto a:us){
    cout<<a<<", ";
  }
  us.erase(13);
  cout<<endl<<"-------Display of unordered_set------"<<endl;
  for(auto a:us){
    cout<<a<<", ";
  }
  return 1;
}
/*
O/P
-------Display of set------
3, 13, 98, 546,
-------Display of unordered_set------
546, 98, 3, 13,
is set empty? 0
No of elements in sets - 4
Absent
Value is present
-------Display of unordered_set------
546, 98, 3, 13,
-------Display of unordered_set------
546, 98, 3,
*/

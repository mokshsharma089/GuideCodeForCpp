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
/*
The functions associated with stack are:
empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)
*/
int main(){

  stack<int> s;
  s.push(5);
  s.push(10);
  s.push(23);

  cout<<endl<<"The topmost element "<<s.top();
  cout<<endl<<"Removing from stack ";
  s.pop();
  cout<<endl<<"The topmost element "<<s.top();
  cout<<endl<<"No of elements in stack "<<s.size();
  cout<<endl<<"Is stack empty "<<s.empty();


  // "s.clear()"" doesnt work have to do it manually.
  return 1;
}
/*
O/P
The topmost element 23
Removing from stack
The topmost element 10
No of elements in stack 2
Is stack empty 0
*/

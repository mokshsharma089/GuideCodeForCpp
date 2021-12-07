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

Q
172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.



Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0

//main thought process count no of times 2 and 5 comes in factorial ,
// minimum of both numbers would be answer as 2*5=10 and without it its not possible
// no of 5 will always be lesser than no of 2s in factorial(see by factorizing)
//ans to problem would be no of times 5 occurs in Factorial
we can find that by running a loop and dividing n by 5
int main(){
  int n;
  cin>>n;
  int ans=0;
  while(n){
    //in first loop iterarion we find the no of integers that are multiples of 5
    //in second loop iteration we find the no of integers that are multiple of 25, (we already added their 5s(which were not of 25s)factorial earlier so just add them to our ans)
    //so on for 125 etc etc.
      n/=5;
      ans+=n;
  }
  cout<<ans;
  return 1;
}
//
// 10/5 =2 because till 10 , we only get 5,10
// 13/5 =2 because till 13 , we only get 5,10
// 15/5 =3 because till 15 , we only get 5,10,15
// 25/5 =6 because 25/5 = 5 + 5/5=1 (5/5 can also be seen as no of items which had 5 twice in their composition)

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
void display(string &s){
  cout<<endl<<"----------Current State of String is--------"<<endl<<s;
}
void doesStringContainSubstring(string str, string substring){
  //  find returns index where pattern is found.
    //  If pattern is not there it returns predefined
    //  constant npos whose value is -1
  if(str.find(substring)!=-1){
    cout<<"\nSub-string found in string at - "<<str.find(substring);
    return;
  }
  else{
    cout<<endl<<"Not found";
  }
}
void toggleCase(string &s){
  for(int i=0;i<s.length();i++){
      char c=s.at(i);//or s[i];
        if(c>='a' and c<='z'){
          s[i]-=32;
        }
        else if(c>='A' and c<='Z'){
          s[i]+=32;
        }
  }
}
int main(){
  string s;
  s="hey this is a string";
  display(s);
  cout<<endl<<"Enter new value for string even whitespaces can be there :- ";
  getline(cin,s);
  display(s);
  cout<<endl<<"Length of string is - "<<s.length();
  cout<<endl<<"String is toggled :-";
  toggleCase(s);
  display(s);
  //emptying the contents of the string
  s.clear();
  cout<<endl<<"is String empty(called clear function just above) - "<<s.empty();

  string str("hi is anybody named moksh present here"),a("here"),b("Obama"),c("hi");
  doesStringContainSubstring(str,a);//Sub-string found in string at - 34
  doesStringContainSubstring(str,b);//Not found
  doesStringContainSubstring(str,c);//Sub-string found in string at - 0

  str.append(" Obama asked everyone");
  doesStringContainSubstring(str,b);//Sub-string found in string at - 39

  // str.substr(startIndex,length) if length is omitted then starting from startIndex till end of the string
  //returns new string rather than changing original
  string n=str.substr(10);
  display(n);//ody named moksh present here Obama asked everyone

  // s.compare(s1) compares strings lexicographically and
  // returns an integer
  // 0 if equal
  // +ve if s is greater
  // -ve if s1 is greater
  s="abcde";
  cout<<endl<<"abcde vs mbcde : "<<s.compare("mbcde");//-12 

  return 1;
}

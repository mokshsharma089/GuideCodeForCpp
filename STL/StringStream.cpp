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
#include <sstream>//used for stringstream
#define pb push_back
using namespace std;
//A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).

int main(){
  string s="Hey look this string has a lot of words and spaces in between     Hey but lets see how it handles double spaces";
  map<string,int> m;
  vector<string> vec;
  int noOfWords=0;

  //main code starts here
  stringstream stream(s);
  string word;
  while(stream>>word){
    vec.push_back(word);
    m[word]++;
    noOfWords++;
  }
  //main code ends here

  cout<<endl<<"----------------All words in a vector format-------------------"<<endl;
  for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<" , ";
  }
  cout<<endl<<"----------------Word Frequency map-------------------"<<endl;
  for(auto a:m){
    cout<<endl<<"key - "<<a.first<<" and value "<<a.second;
  }
  cout<<endl<<"----------------No of words ------------------- "<<noOfWords;

  cout<<endl<<"----------------Using String Stream to tokenize a string about any character------------------- "<<endl;
  cout<<endl<<"----------------Using String Stream to tokenize a string about ','------------------- "<<endl;
  //use getline(streamName,tempString,char) here using it with while loop like below
  stringstream stream1("i,moksh,sharma,available,to,work");
  while(getline(stream1,word,',')){
    cout<<endl<<word;
  }
  //to reuse a string stream first .clear then set with .str();
  stream1.clear();
  stream1.str("I_want_this_string_split_with_respect_to_underscore");
  cout<<endl<<"----------------Using String Stream to tokenize a string about '_'------------------- "<<endl;
  while(getline(stream1,word,'_')){
    cout<<endl<<word;
  }
  return 1;
}
//
// O/P
//
// ----------------All words in a vector format-------------------
// Hey , look , this , string , has , a , lot , of , words , and , spaces , in , between , Hey , but , lets , see , how , it , handles , double , spaces ,
// ----------------Word Frequency map-------------------
//
// key - Hey and value 2
// key - a and value 1
// key - and and value 1
// key - between and value 1
// key - but and value 1
// key - double and value 1
// key - handles and value 1
// key - has and value 1
// key - how and value 1
// key - in and value 1
// key - it and value 1
// key - lets and value 1
// key - look and value 1
// key - lot and value 1
// key - of and value 1
// key - see and value 1
// key - spaces and value 2
// key - string and value 1
// key - this and value 1
// key - words and value 1
// ----------------No of words ------------------- 22
//
// ----------------Using String Stream to tokenize a string about any character-------------------
//
// ----------------Using String Stream to tokenize a string about ','-------------------
//
// i
// moksh
// sharma
// available
// to
// work
// ----------------Using String Stream to tokenize a string about '_'-------------------
//
// I
// want
// this
// string
// split
// with
// respect
// to
// underscore

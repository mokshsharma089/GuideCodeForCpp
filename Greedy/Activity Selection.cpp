// Greedy problem

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
struct A{
  string name;
  int st,et;
  //represent start and end times respectively
};
bool basis(A a,A b){
    if(a.et < b.et){
      return true;
    }
    return false;
}

void ActivitySelection(vector<A>& ls){
  sort(ls.begin(),ls.end(),basis);
  cout<<endl<<"--------------SELECTED ACTIVITIES ARE--------------";
  int etime=ls[0].et,count=1;
  cout<<endl<<count++<<". "<<ls[0].name;
  for(int i=1;i<ls.size();i++){
    if(etime<=ls[i].st){
      cout<<endl<<count++<<". "<<ls[i].name;
    }
  }
}

int main(){
  vector<A> ls;
  A a;
  a.name="A";
  a.st=1;
  a.et=3;
  ls.push_back(a);
  A b;
  b.name="B";
  b.st=3;
  b.et=6;
  ls.push_back(b);
  A c;
  c.name="C";
  c.st=2;
  c.et=4;
  ls.push_back(c);
  A d;
  d.name="D";
  d.st=6;
  d.et=100;
  ls.push_back(d);
  for(auto a:ls){
    cout<<endl<<a.name<<" starts at : "<<a.st<<" , ends at :"<<a.et;
  }
  cout<<endl;
  ActivitySelection(ls);
  cout<<endl;
  return 1;
}

#include <iostream>
#include <vector>
#include <cstdlib>//for rand() function
#include <algorithm>
#define pb push_back
using namespace std;
void display(vector<int>& arr){
  cout<<endl<<"-----------------Current State Of Array-----------------"<<endl;
  for(auto a:arr){
    cout<<a<<" , ";
  }
  cout<<endl<<"---------------------------------------------------------"<<endl;
}
void InsertionSort(vector<int>& arr){
  int i,n=arr.size(),j,curr;
  for(i=1;i<n;i++){
    curr=arr[i];
    cout<<"\nRound "<<i+1<<" , Putting "<<arr[i]<<" at right place and array till index "<<i<<" is sorted now";
    j=i-1;
    while(j>=0 and arr[j]>curr){
      arr[j+1]=arr[j];
      j--;
    }
    if(j!=i-1){
      arr[j+1]=curr;
    }
  }
}
int main(){
  vector<int> a;
  for(int i=0;i<25;i++){
    a.pb(rand()%1000+1);
  }
  cout<<"\nBefore Sorting";
  display(a);
  InsertionSort(a);
  cout<<"\nAfter Sorting";
  display(a);
  return 1;
}

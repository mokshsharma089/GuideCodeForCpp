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
void selectionSort(vector<int> &arr){
  int i,j,min,n=arr.size();
  for(i=0;i<n;i++){
    cout<<"\nRound "<<i+1;
    min=i;
    for(j=i;j<n;j++){
      if(arr[min]>arr[j]){
        min=j;
      }
    }
    if(min!=i){
      swap(arr[min],arr[i]);
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
  selectionSort(a);
  cout<<"\nAfter Sorting";
  display(a);
  return 1;
}

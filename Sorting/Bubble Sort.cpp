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
void bubbleSort(vector<int>& arr){
  int i,j,n=arr.size();
  for(i=0;i<n;i++){

    bool flag=false;
    for(j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        flag=true;
        swap(arr[j],arr[j+1]);
      }
    }
    cout<<"\nRound "<<i+1<<" , "<<arr[n-i-1]<<" element at right place";
    if(flag==false){
      cout<<endl<<"Breaking because no need to sort any more";
      break;
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
  bubbleSort(a);
  cout<<"\nAfter Sorting";
  display(a);
  return 1;
}

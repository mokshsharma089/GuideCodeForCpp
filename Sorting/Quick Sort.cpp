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
void QuickSort(vector<int>& arr,int start,int end){
    if(start>=end){
      return;
    }
    int l=start,r=end,pivot,range=end-start;
    pivot=arr[rand()%range+start];//takes a random element between start and end
    while(l<=r){
      while(arr[l]<pivot){
        l++;
      }
      while(arr[r]>pivot){
        r--;
      }
      if(l<=r){
        swap(arr[l],arr[r]);
        l++;
        r--;
      }
    }
    cout<<endl<<"Pivot = "<<pivot<<" Placed at its correct postion . Start ="<<start<<" and end = "<<end;
    QuickSort(arr,start,r);
    QuickSort(arr,l,end);
}
int main(){
  vector<int> a;
  for(int i=0;i<25;i++){
    a.pb(rand()%1000+1);
  }
  cout<<"\nBefore Sorting";
  display(a);
  QuickSort(a,0,a.size()-1);
  cout<<"\nAfter Sorting";
  display(a);
  return 1;
}

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
void Merge(vector<int>&,int,int,int);
void MergseSort(vector<int>& arr,int start,int end){
  if(start>=end){
    return;
  }
  int mid=start+(end-start)/2;
  MergseSort(arr,start,mid);
  MergseSort(arr,mid+1,end);
  Merge(arr,start,mid,end);
  return;
}
void Merge(vector<int>& arr,int start,int mid,int end){
  int temp[end-start+1];
  int i=start,j=mid+1,k=0;
  cout<<endl<<"Merge called for start = "<<start<<" and end = "<<end;
  while(i<=mid and j<=end){
    if(arr[i]<arr[j]){
      temp[k]=arr[i];
      i++;
      k++;
    }
    else{
      temp[k]=arr[j];
      j++;
      k++;
    }
  }
  while(i<=mid){
    temp[k]=arr[i];
    i++;
    k++;
  }
  while(j<=end){
    temp[k]=arr[j];
    j++;
    k++;
  }
  k=0;
  for(i=start;i<=end;i++,k++){
    arr[i]=temp[k];
  }
}
int main(){
  vector<int> a;
  for(int i=0;i<25;i++){
    a.pb(rand()%1000+1);
  }
  cout<<"\nBefore Sorting";
  display(a);
  MergseSort(a,0,a.size()-1);
  cout<<"\nAfter Sorting";
  display(a);
  return 1;
}

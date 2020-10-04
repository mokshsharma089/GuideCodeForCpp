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
void DownHeapify(vector<int>& arr,int idx,int range){
  int Lchild,Rchild,max;
  Lchild=2*idx+1;
  Rchild=2*idx+2;
  if(Lchild > range and Rchild > range){
    return;
  }
  max=idx;
  if(Lchild<=range and arr[Lchild] > arr[max]){
    max=Lchild;
  }
  if(Rchild<=range and arr[Rchild] > arr[max]){
    max=Rchild;
  }
  if(max!=idx){
    swap(arr[max],arr[idx]);
    DownHeapify(arr,max,range);
  }
}
void makeHeap(vector<int>& arr){
  int size=arr.size()-1,i;
  int mid=size/2;
  for(i=mid;i>=0;i--){
    DownHeapify(arr,i,size);
  }
}
void HeapSort(vector<int>& arr){
  makeHeap(arr);
  int size=arr.size()-1;
  for(int i=size;i>0;i--){
    swap(arr[0],arr[i]);
    DownHeapify(arr,0,i-1);
  }
}
int main(){
  vector<int> a;
  for(int i=0;i<25;i++){
    a.pb(rand()%1000+1);
  }
  cout<<"\nBefore Sorting";
  display(a);
  HeapSort(a);
  cout<<"\nAfter Sorting";
  display(a);
  return 1;
}

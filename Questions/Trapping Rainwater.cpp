#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Leetcode 42.
// Trapping Rain Water
//
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
//
// Example:
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

// Algorithm
// Precompute the height of longest bar (including self) to left and right of each bar
// contribution to water stored of bar i can be found by using below formula
// water at index[i]=min(A[i],B[i])-height[i]

int trapWater(vector<int>& height) {
        int n=height.size()-1;
        if(n==-1){
            //if array is empty
            return 0;
        }
        int A[n+1],B[n+1];
        //A would store the height of the longest bar(including self) to the left side of bar at index at i(at height vector {or bar number i+1 if bar number of bar at index 0 is 1})
        //B would store for height of the longest bar(including self) to the right side of the bar
        //amount of water collected at any bar i can be found using the formula
        //water at index[i]=min(A[i],B[i])-height[i]
        //here min is used as the amount of water that can be stored is as much as smallest boundary(right or left ) -  height of current bar
        A[0]=height[0];//highest bar to the left of first bar can be the bar itself only
        int max_to_left=A[0];
        for(int i=1;i<=n;i++){
            if(height[i]>max_to_left){
                A[i]=height[i];
                max_to_left=A[i];
            }
            else{
                A[i]=max_to_left;
            }
        }
        B[n]=height[n];//highest bar to the right of last bar can be the bar itself only
        int max_to_right=B[n];
        for(int i=n-1;i>=0;i--){
            if(height[i]>max_to_right){
                B[i]=height[i];
                max_to_right=B[i];
            }
            else{
                B[i]=max_to_right;
            }
        }
        int amount_of_water_stored=0;
        for(int i=0;i<=n;i++){
            amount_of_water_stored+=min(A[i],B[i])-height[i];
        }
        return amount_of_water_stored;
    }

int main(){
  vector<int> h;
  h.push_back(1);
  h.push_back(10);
  h.push_back(2);
  h.push_back(100);
  //1 10 2 100 water would only be stored at bar '2' at index 3 which is min(10,100)-2=8
  cout<<endl<<trapWater(h);
  return 1;
}

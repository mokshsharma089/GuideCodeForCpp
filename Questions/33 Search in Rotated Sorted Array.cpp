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
// There is an integer array nums sorted in ascending order (with distinct values).
//
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
//
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
// or -1 if it is not in nums.
//
// You must write an algorithm with O(log n) runtime complexity.
//
// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//
// Example 3:
// Input: nums = [1], target = 0
// Output: -1
//
// Algorithm-
// 1. find the pivot by binary search
// 2. perform binary search in right partition of array acc to pivot and target
//
// TC - O(log(n))
// SC - O()
int findPivot(vector<int> &nums){
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid==nums.size()-1){
                return mid;
            }
            if(nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>=nums[end]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return start;
    }
int binarySearch(vector<int>& nums, int start, int end,int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
int search(vector<int>& nums, int target) {
        //1 find the pivot
        //2 search in the right part of the array
        int pivot=findPivot(nums);
        cout<<"Pivot found at "<<pivot<<" and value of pivot is "<<nums[pivot];
        int ans=-1;
        if(pivot!=nums.size()-1){
            if(target>=nums[0] and target<=nums[pivot]){
                ans=binarySearch(nums,0,pivot,target);
                cout<<"\n Binary Search called for 0 and "<<pivot;
            }
            else{
                ans=binarySearch(nums,pivot+1,nums.size()-1,target);
                cout<<"\n Binary Search called for"<<pivot<<" and "<<nums.size()-1;
            }
        }
        else{
            ans=binarySearch(nums,0,nums.size()-1,target);
        }
        return ans;

    }
int main(){

  vector<int> vec;
  //fill code here

  return 1;
}

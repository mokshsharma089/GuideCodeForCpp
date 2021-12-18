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

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//
// If target is not found in the array, return [-1, -1].
//
// You must write an algorithm with O(log n) runtime complexity.
//
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//
// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

// TC-O(log(n))
// SC-O(1)
vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(lower(nums,target));
        if(result[0]==-1){
            result.push_back(-1);
            return result;
        }
        result.push_back(upper(nums,target));
        return result;
    }
    int upper(vector<int>& nums,int target){
        int ans=-1;
        int start=0,end=nums.size()-1;
        while(start>=0 and end<nums.size() and start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    int lower(vector<int>& nums,int target){
        int ans=-1;
        int start=0,end=nums.size()-1;
        while(start>=0 and end<nums.size() and start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
int main(){


  return 1;
}

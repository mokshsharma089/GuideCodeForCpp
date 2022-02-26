334. Increasing Triplet Subsequence
Medium


Given an integer array nums, return true if there exists a triple of indices (i, j, k)
such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.


Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

Algorithm-
1. take 2 variables smallest, secondSmallest,
2. traverse the array
  if value is less than equal to smallest, make smallest=nums[i]
  else if value is less than equal to secondSmallest, make secondSmallest=nums[i]
  else condition is satisfied then return true;

Code-
bool increasingTriplet(vector<int>& nums) {
        int value_At_I=nums[0],value_At_J=INT_MAX;

        for(int k=1;k<nums.size();k++){
            int value_At_K=nums[k];
            if(value_At_K<=value_At_I){
                value_At_I=value_At_K;
            }
            else if(value_At_K<=value_At_J){
                value_At_J=value_At_K;
            }
            else{
                return true;
            }
        }
        return false;
    }


TC- O(N)
SC- O(1)

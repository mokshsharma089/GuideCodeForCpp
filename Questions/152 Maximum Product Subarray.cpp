152. Maximum Product Subarray
Medium

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product,
and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.



Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:=
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


Basic Intuition-
1.lets assume there are no zeroes in the array
2.If no. of -ve numbers is even no issues max product would be product of all elements
[-1,,5,9,-4] max product = 1*5*9*4=180 as 2 -vs cancel each other

3.If no. of -ve numbers is odd, then leave till 1st -ve element and take product of rest of the elements,
and in next case leave the from last -ve element to the end, and take product of rest of the element .
Compare Both and return max
eg-
[2,-1,2,3,-4,9,-2,8]
take product of subarray [2,-1,2,3,-4,9] and [2,3,-4,9,-2,8] and check which gives maximum and return max

4.If there are zeroes in the array
5.whenever we encounter zero move ahead and start product again
[-8,-9,0,7,6]
find max out of [-8,-9] and [7,6] and return maximum

Code-
A lot like kadanes algo but keeps above intuition in mind
and 2nd loop for checking both condition in 3
for 4 and 5 condition just make currProd=1 whenever we get 0 and new ans would start


Can be done in one pass also but written so can understand better

int maxProduct(vector<int>& nums) {
       int res=nums[0];
       int currProd=1;

       for(int i=0;i<nums.size();i++){
           currProd*=nums[i];
           res=max(res,currProd);
           if(nums[i]==0){
               currProd=1;
           }
       }

       currProd=1;
       for(int i=nums.size()-1;i>=0;i--){
           currProd*=nums[i];
           res=max(res,currProd);
           if(nums[i]==0){
               currProd=1;
           }
       }
       return res;
   }


   TC-O(N)
   SC-O(1)

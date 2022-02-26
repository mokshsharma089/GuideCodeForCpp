697. Degree of an Array


Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.



Example 1:

Input: nums = [1,2,2,3,1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation:
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.


Algo -
1.traverse the array and find the first and last occurance of every element and store in hashmap
2.find Degree
3.traverse all elements of hashmap and see which element has a degree same as whole array and has smallest subarray length based on first and last occurence

Code-
class Solution {
public:
    class help{
        public:
        int idx_1;//stores first_occurnce of that character
        int idx_2;//store last_occurance of that character
        int freq;
        help(){
            this->freq=1;
        }
    };
    int findShortestSubArray(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_map<int,help> m;
        int degree=1;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])==0){
                //if element has not been encountered before so first entry in hashmap
                help temp;
                temp.idx_1=i;
                temp.idx_2=i;
                m[nums[i]]=temp;
                // cout<<"\nHashmap record for "<<nums[i]<<" - "<<"first Occ-"<<m[nums[i]].idx_1<<" last Occ- "<<m[nums[i]].idx_2<<" and freq-"<<m[nums[i]].freq;
            }
            else{
                //if element has been encountered so just update older entry
                m[nums[i]].freq++;
                m[nums[i]].idx_2=i;
                degree=max(degree,m[nums[i]].freq);
                // cout<<"\nHashmap record for "<<nums[i]<<" - "<<"first Occ-"<<m[nums[i]].idx_1<<" last Occ- "<<m[nums[i]].idx_2<<" and freq-"<<m[nums[i]].freq;
            }
        }
        // cout<<"\n Degree of array is"<<degree;
        int ans=INT_MAX;
        for(auto ele:m){
            if(ele.second.freq==degree){
                int localAns=ele.second.idx_2-ele.second.idx_1+1;
                ans=min(ans,localAns);
            }
        }
        return ans;
    }
};

Time complexity - O(N)
Space complexity - O(N)

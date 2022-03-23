264. Ugly Number II
Medium

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.


Intuition -
ugly numbers= [1] so Next ugly number would be min(1*2,1*3,1*5) ie 2
ugly numbers = [1,2] so next ugly number would be min(2*2,1*3,1*5) ie 3
ugly numbers = [1,2,3] so next ugly number would be min(2*2,2*3,1*5) ie 4
ugly numbers = [1,2,3,4] so next ugly number would be min(3*2,2*3,1*5) ie 5
ugly numbers  = [1,2,3,4,5] so next ugly number would be min(3*2, 2*3, 2*5) ie 6
ugly numbers = [1,2,3,4,5,6] so next ugly number would be min (4*2,3*3,2*5) ie 8 and so on

TC - O(N)
SC - O(N)

Code-
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,-1);
        int idx2=0;
        int idx3=0;
        int idx5=0;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int val2 = dp[idx2]*2;
            int val3 = dp[idx3]*3;
            int val5 = dp[idx5]*5;
            dp[i] = min(val2,min(val3,val5));

            if(dp[i]==val2){
                // cout<<"\n filling the value of "<<i<<" as "<<dp[i]<<" and moving idx2 "<<idx2+1<<" where dp value is "<<dp[idx2+1];
                idx2++;
            }
            if(dp[i]==val3){
                // cout<<"\n filling the value of "<<i<<" as "<<dp[i]<<" and moving idx3 "<<idx3+1<<" where dp value is "<<dp[idx3+1];
                idx3++;
            }
            if(dp[i]==val5){
                // cout<<"\n filling the value of "<<i<<" as "<<dp[i]<<" and moving idx5 "<<idx5+1<<" where dp value is "<<dp[idx5+1];
                idx5++;
            }

        }
        return dp[n-1];
    }
};

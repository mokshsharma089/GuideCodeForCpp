123. Best Time to Buy and Sell Stock III
Hard

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

TC - O(N)
SC - O(N)


Code -

int maxProfit(vector<int>& prices) {
      vector<int> firstSale(prices.size(),0), secondSale(prices.size(),0);
       int minValueToTheLeft = prices[0];
       int maxValueToTheRight = prices[prices.size()-1];

       //First we calculate the profits if we are buying at the minimum value that occured before that index and selling at here
       //go left to right here
       //here i index denotes where we are selling the first stock
       for(int i=1;i<prices.size();i++){
           minValueToTheLeft = min(minValueToTheLeft,prices[i]);
           firstSale[i] = max(firstSale[i-1],prices[i]-minValueToTheLeft);
       }

       //Secondly we calculate the profits for second sale, selling at the maximum value occuring after it for every index we go to
       //go from right to left
       //here i index denotes where we are buying the second stock
       for(int i=prices.size()-2;i>=0;i--){
           maxValueToTheRight=max(maxValueToTheRight,prices[i]);
           secondSale[i]=max(secondSale[i+1],maxValueToTheRight-prices[i]);
       }

       int result=0;
       //just traverse the array and find the maximum possible sum of both sales
       for(int i=0;i<prices.size();i++){
           int temp;
           temp=firstSale[i]+secondSale[i];
           result=max(result,temp);
       }

       return result;
   }

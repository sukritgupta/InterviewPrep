You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
Constraints:
	• 1 <= prices.length <= 105
	• 0 <= prices[i] <= 104

From <https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/> 

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        return bestSaleDay(prices);
    }
    int bestSaleDay(vector<int>& prices){
        int maxP = 0;
        int days = prices.size();
        vector<int> maxPossPrice(days);
        
        int curMax = prices[days-1];
        for(int i= days-1; i>=0; --i){
            curMax = max(curMax, prices[i]);
            maxPossPrice[i] = curMax;
        }
        for(size_t i=0; i<days; ++i){
            maxP = max(maxP, maxPossPrice[i]-prices[i]);
        }
        retun maxP;
    }
    int bruteForce(vector<int>& prices){
        int maxP = 0;
        for(size_t i=0; i<prices.size(); ++i){
            for(size_t j=i+1; j<prices.size();++j){
                if(prices[j]-prices[i]>maxP){
                    maxP = prices[j]-prices[i];
                }
            }
        }
        return maxP;
    }
```

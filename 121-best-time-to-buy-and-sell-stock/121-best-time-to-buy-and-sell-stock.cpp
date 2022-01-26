/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

TC - O(N) where N is no of days. 
SC - O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        //minPrice stores the minimum price of the stock before current day.
        int minPrice=prices[0];
        int maxProfit=0;
        for(int day=1;day<prices.size();day++)
        {
            //maxProfit stores the profit if we will sell current day and profit till now.
            maxProfit= max(maxProfit,prices[day]-minPrice);
            //update the minPrice of stocks till for next day. 
            minPrice = min(minPrice,prices[day]);
        }
        return maxProfit;
    }
};
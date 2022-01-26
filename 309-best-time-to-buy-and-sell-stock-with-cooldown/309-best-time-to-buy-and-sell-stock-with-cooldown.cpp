/*
Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/
TC - O(N)
SC - O(1)

Approach - This is similar to the fees que, there we were refering to last day's states
Here, for selling we will refer to last day's states
But for buying, we will take yesterday's prev day's sell prof as last day is cooldown day, so we can't buy today if we have sold yesterday
*/

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int prevSellProfit=0;
        int lastBuyProfit = -1*prices[0];
        int lastSellProfit = 0;
    
        for(int i=1;i<prices.size();i++)
        {
            int newLastSellProfit=max(lastSellProfit,prices[i]+lastBuyProfit);
            int newLastBuyProfit = max(lastBuyProfit,prevSellProfit-prices[i]);

            prevSellProfit=lastSellProfit;
            lastSellProfit=newLastSellProfit;
            lastBuyProfit=newLastBuyProfit;
        }
        return lastSellProfit;
    }
};
/*
Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/
TC - O(N)
SC - O(1)
*/

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int lastBuy = -1*prices[0];
        int lastSell = 0;
        int n =prices.size();
        int newLastBuy;
        int newLastSell;
        for(int i=1;i<n;i++)
        {
            newLastBuy = max(lastBuy,lastSell-prices[i]);
            newLastSell = max(lastBuy+prices[i]-fee,lastSell);
            
            lastBuy=newLastBuy;
            lastSell=newLastSell;
        }
        return lastSell;
    }
};
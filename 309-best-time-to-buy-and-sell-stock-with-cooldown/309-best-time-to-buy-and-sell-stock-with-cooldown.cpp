class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int prevSell=0;
        int lastBuy = -1*prices[0];
        int lastSell = 0;
    
        for(int i=1;i<prices.size();i++)
        {
            int newLastSell=max(lastSell,prices[i]+lastBuy);
            int newLastBuy = max(lastBuy,prevSell-prices[i]);

            prevSell=lastSell;
            lastSell=newLastSell;
            lastBuy=newLastBuy;
        }
        return lastSell;
    }
};
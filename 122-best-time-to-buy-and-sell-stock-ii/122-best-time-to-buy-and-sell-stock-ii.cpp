class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int maxProfit =0;
        int buy=0;
        int sell=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]>=prices[i-1])
                sell++;
            else
            {
                maxProfit+=(prices[sell]-prices[buy]);
                sell=i;
                buy=i;
            }
            if(i==n-1)
                maxProfit+=(prices[sell]-prices[buy]);
        }
        return maxProfit;
    }
};
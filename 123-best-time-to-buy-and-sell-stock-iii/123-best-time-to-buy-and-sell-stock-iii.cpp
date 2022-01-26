class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> buyTillCurrDay(n,0);
        vector<int> sellTillCurrDay(n,0);
        
        int minPrice = prices[0];
        for(int i=1;i<n;i++)
        {
            sellTillCurrDay[i]=max(sellTillCurrDay[i-1],prices[i]-minPrice);
            minPrice=min(minPrice,prices[i]);
        }
        
        int maxPrice = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            buyTillCurrDay[i]=max(buyTillCurrDay[i+1],maxPrice-prices[i]);
            maxPrice=max(maxPrice,prices[i]);
        }
        
        int maxProfit=0;
        for(int i=0;i<n;i++)
        {
            maxProfit=max(maxProfit,sellTillCurrDay[i]+buyTillCurrDay[i]);
        }
        return maxProfit;
    }
};
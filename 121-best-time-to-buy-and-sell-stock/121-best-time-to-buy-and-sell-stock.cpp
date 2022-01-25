class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
    
        int maxProfit = INT_MIN;
        int minTillCurr = INT_MAX;
        minTillCurr=prices[0];
        
        for(int i=1;i<n;i++)
        {
            maxProfit = max(maxProfit, prices[i]-minTillCurr);
            minTillCurr=min(minTillCurr,prices[i]);
        }
        
        if(maxProfit<0)
            return 0;
        return maxProfit;
    }
};
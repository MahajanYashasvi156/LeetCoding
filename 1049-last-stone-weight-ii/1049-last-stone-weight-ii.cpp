class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int totalSum = 0;
        
        for(int s:stones)
            totalSum+=s;
        
        int s1 = totalSum/2;
        
        vector<bool> dp(s1+1,0);
        
        dp[0] = true;
        
        for(int i=0;i<stones.size();i++)
        {
            for(int j = s1;j>=0;j--)
            {
                if(j>=stones[i])
                {
                    dp[j] = dp[j] || dp[j-stones[i]];
                }
            }
        }
        
        for(int i = s1;i>=0;i--)
        {
            if(dp[i])
                return totalSum - 2*i;
        }
        return totalSum;
    }
};
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int totalSum = 0;
        for(int s : nums)
            totalSum+=s;
        
        if(totalSum<target || (totalSum - target)%2)
               return 0;
        int s2 = (totalSum - target)/2;
        
        vector<int> dp(s2+1,0);

        dp[0] = 1;

        for(int i = 0;i<nums.size();i++)
        {
            for(int j = s2;j>=0;j--)
            {
                if(j>=nums[i])
                {
                    dp[j] = (dp[j] + dp[j-nums[i]])%1000000007;
                }
            }
        }
        
       return dp[s2];
        
    }
};
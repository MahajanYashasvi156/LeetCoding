class Solution 
{
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        vector<vector<int>> dp(nums.size(),vector<int>(1002,0));
        
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                int diff = 500+nums[i]-nums[j];
                dp[i][diff] = dp[j][diff]==0? 2: dp[j][diff]+1;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
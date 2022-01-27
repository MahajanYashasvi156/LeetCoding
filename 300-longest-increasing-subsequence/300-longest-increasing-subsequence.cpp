class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            int maxLISEndAti = 0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    maxLISEndAti = max(maxLISEndAti,dp[j]);
            }
            dp[i]+=maxLISEndAti;
            cout<<dp[i];
        }
        
        int maxLIS = 1;
        for(int i=1;i<n;i++)
        {
            maxLIS = max(maxLIS,dp[i]);
        }
        return maxLIS;
    }
};
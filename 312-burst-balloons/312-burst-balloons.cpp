class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int l=1;l<=n;l++)
        {
            for(int i = 0 ;i<=n-l;i++)
            {
                int j = i+l-1;
                int left = 1;
                int right = 1;
                
                if(i-1>=0)
                    left = nums[i-1];
                if(j+1<n)
                    right = nums[j+1];
                
                if(l==1)
                    dp[i][j]= left*nums[i]*right;
               
                else
                {
                    for(int k = i;k<=j;k++)
                    {
                        if(k==0)
                            dp[i][j]=max(dp[i][j],dp[k+1][j]+left*nums[k]*right);
                        else if(k==n-1)
                            dp[i][j]=max(dp[i][j],dp[i][k-1]+left*nums[k]*right);
                        else
                            dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+left*nums[k]*right);
                    }    
                }
            }
        }
        return dp[0][n-1];
    }
};
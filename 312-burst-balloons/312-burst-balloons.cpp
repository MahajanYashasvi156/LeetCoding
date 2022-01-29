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
                        int leftSubProblem = 0;
                        int rightSubProblem = 0;
                        
                        if(k!=0)
                            leftSubProblem = dp[i][k-1];
                         if(k!=n-1)
                            rightSubProblem = dp[k+1][j];
                        
                        dp[i][j]=max(dp[i][j],leftSubProblem+rightSubProblem+left*nums[k]*right);
                    }    
                }
            }
        }
        return dp[0][n-1];
    }
};
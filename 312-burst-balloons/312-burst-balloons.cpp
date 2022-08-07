class Solution 
{
public:
    int MCM(vector<int>&nums,vector<vector<int>>&dp,int l,int r)
    {
        if(l>=r)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        dp[l][r] = INT_MIN;
        for(int p = l;p<r;p++)
        {
            int currCoins = MCM(nums,dp,l,p)+  MCM(nums,dp,p+1,r) + nums[l-1]*nums[p]*nums[r];
            
            dp[l][r] = max(dp[l][r],currCoins);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        
        return MCM(nums,dp,1,nums.size()-1);
    }
};
























/*
Link - https://leetcode.com/problems/burst-balloons/submissions/

TC - O(N^3)
SC - O(N^2)

Application of MCM.

Each cell represents maximum coins collected bursting that ballons(considering them to be in the nums array itself.)


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
*/

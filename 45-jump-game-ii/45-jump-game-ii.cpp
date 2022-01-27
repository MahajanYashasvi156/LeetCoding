/*
Link - https://leetcode.com/problems/jump-game-ii/
TC - O(N^2)
SC - O(N)

class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;
        for(int i = n-2;i>=0;i--)
        {
            for(int j = i+1;j<nums.size() && j<=i+nums[i];j++)
            {
                if(dp[j]!=INT_MAX)
                    dp[i]=min(dp[i],dp[j]+1);
            }
        }
        return dp[0];
    }
};
*/

class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        int currReach = 0;
        int maxReach = 0;
        int jumps=0;
        
        for(int i=0;i<n-1;i++)
        {
            maxReach=max(maxReach,i+nums[i]);
            if(i==currReach)
            {
                currReach=maxReach ;
                jumps++;
            }
            
            cout<<i<<" "<<currReach<<endl;
        }
        return jumps;
    }
};
/*
Be Naive First

When I first get this problem, it is far from dynamic programming to me. I started with the most naive idea the backtracking.

We have n balloons to burst, which mean we have n steps in the game. In the i th step we have n-i balloons to burst, i = 0~n-1. Therefore we are looking at an algorithm of O(n!). Well, it is slow, probably works for n < 12 only.

Of course this is not the point to implement it. We need to identify the redundant works we did in it and try to optimize.

Well, we can find that for any balloons left the maxCoins does not depends on the balloons already bursted. This indicate that we can use memorization (top down) or dynamic programming (bottom up) for all the cases from small numbers of balloon until n balloons. How many cases are there? For k balloons there are C(n, k) cases and for each case it need to scan the k balloons to compare. The sum is quite big still. It is better than O(n!) but worse than O(2^n).

Better idea

We then think can we apply the divide and conquer technique? After all there seems to be many self similar sub problems from the previous analysis.

Well, the nature way to divide the problem is burst one balloon and separate the balloons into 2 sub sections one on the left and one one the right. However, in this problem the left and right become adjacent and have effects on the maxCoins in the future.

Then another interesting idea come up. Which is quite often seen in dp problem analysis. That is reverse thinking. Like I said the coins you get for a balloon does not depend on the balloons already burst. Therefore
instead of divide the problem by the first balloon to burst, we divide the problem by the last balloon to burst.

Why is that? Because only the first and last balloons we are sure of their adjacent balloons before hand!

For the first we have nums[i-1]*nums[i]*nums[i+1] for the last we have nums[-1]*nums[i]*nums[n].

OK. Think about n balloons if i is the last one to burst, what now?

We can see that the balloons is again separated into 2 sections. But this time since the balloon i is the last balloon of all to burst, the left and right section now has well defined boundary and do not affect each other! Therefore we can do either recursive method with memoization or dp.

Final

Here comes the final solutions. Note that we put 2 balloons with 1 as boundaries and also burst all the zero balloons in the first round since they won't give any coins.
The algorithm runs in O(n^3) which can be easily seen from the 3 loops in dp solution.
*/
/*
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


*/
/*
Link - https://leetcode.com/problems/burst-balloons/submissions/

TC - O(N^3)
SC - O(N^2)

Application of MCM.

Each cell represents maximum coins collected bursting that ballons(considering them to be in the nums array itself.)

*/
class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        
        for(int l=2;l<=n;l++)
        {
            for(int i = 1 ;i<=n-l;i++)
            {
                int j = i+l-1;
               
                for(int p = i;p<j;p++)
                {
                    dp[i][j]=max(dp[i][j],dp[i][p]+dp[p+1][j]+nums[i-1]*nums[p]*nums[j]);
                }    
            }
        }
        return dp[1][n-1];
    }
};


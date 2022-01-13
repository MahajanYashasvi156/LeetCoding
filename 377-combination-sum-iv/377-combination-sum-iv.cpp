/*
Problem - Similare to Coin Change Permuations.

Link - https://leetcode.com/problems/combination-sum-iv/submissions/

TC - O(n*target) , where n is the size of nums or number of coins.
SC - O(target)

At smaller step explore possibility with all coins then only go to higher amount/target.
*/
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<double>dp(target+1,0);
            
        dp[0]=1;
        
        for(int i=1;i<=target;i++)
        {
            for(int coin:nums)
                if(i>=coin)
                    dp[i]+=dp[i-coin];
        }
        return dp[target];
    }
};
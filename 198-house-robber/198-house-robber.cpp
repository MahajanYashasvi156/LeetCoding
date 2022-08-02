class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            int pick = nums[i];
            if(i>1)
                pick+=dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[nums.size()-1];
    }
};


/*

*/
/*
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        vector<int> pick(nums.size(),0);
        vector<int> Notpick(nums.size(),0);
        
        pick[0] = nums[0];
        
        for(int i = 1;i<nums.size();i++)
        {
            Notpick[i] = pick[i-1];
            
            if(i==1)
                pick[i] = nums[i];
            else
                pick[i] = max(pick[i-2],Notpick[i-2])+nums[i];  
        }
        
        return max(pick[nums.size()-1],Notpick[nums.size()-1]);
    }
};
*/
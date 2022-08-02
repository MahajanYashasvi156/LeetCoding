class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int prev = nums[0];
        int prev2;
        for(int i = 1;i<nums.size();i++)
        {
            int pick = nums[i];
            if(i>1)
                pick+=prev2;
            int notPick = prev;
            prev2 = prev;
            prev = max(pick,notPick);
        }
        return prev;
        
    }
};

/*
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
*/
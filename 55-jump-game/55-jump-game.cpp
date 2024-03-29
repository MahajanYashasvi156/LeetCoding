/*
Link - https://leetcode.com/problems/jump-game
TC - O(N^2)
SC - O(N)

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0; i--)
        {
            for(int j=i+1;j<=i+nums[i] && j<n;j++)
            {
                if(dp[j]==true)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
*/

/*
TC - O(N)
SC - O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int currentWinIndex = n-1;
        for(int i=n-1;i>=0; i--)
        {
            int maxReachableIndex = i+nums[i];
            if(maxReachableIndex>=currentWinIndex)
            {
                currentWinIndex=i;
            }
        }
        return currentWinIndex==0;
    }
};
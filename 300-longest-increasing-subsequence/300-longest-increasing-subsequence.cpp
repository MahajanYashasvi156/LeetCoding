/*
    O(Nlogn)
    Binary Search - 
    
    5 4 3 6 7 4
    
    Always try to take smaller elements in the subsequence.
    
    5 
    
    replace 5 with 4
    
    4 
    
    replace 4 with 3
    
    3 6 7 
    
    replace 6 with 4
    
    3 4 7  ->LIS
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> res;
        
        for(int i = 0;i<nums.size();i++)
        {
            auto it = lower_bound(res.begin(),res.end(),nums[i]);
            
            if(it==res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return res.size();
    }
};


/*
Link - https://leetcode.com/problems/longest-increasing-subsequence/submissions/
TC - O(N^2)
SC - O(N)

Meaning - Entry of ith cell of dp represents length of largest increasing subsequence ending at ith number.

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
        }
        return *max_element(dp.begin(),dp.end());
    }
};
*/

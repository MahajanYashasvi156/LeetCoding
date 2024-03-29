/*
1. Sort the array nums.
2. Use two pointers approach: Given an index i (choose it as the minimum in a subsequence) find the maximum j where j ≥ i and nums[i] +nums[j] ≤ target.
3. Count the number of subsequences.
*/
class Solution 
{
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        vector<int> dp(nums.size(),1);
        for(int i = 1;i<nums.size();i++)
            dp[i] = (dp[i-1]*2)%1000000007;
        
        sort(nums.begin(),nums.end());
        
        int low = 0;
        int high = nums.size()-1;
        int count = 0;
        
        while(low<=high)
        {
           if(nums[high]+nums[low]>target)
               high--;
            else
            {
                count = (count +dp[high-low])%1000000007;
                low++;
            }
        }
        
        return count;
    }
};
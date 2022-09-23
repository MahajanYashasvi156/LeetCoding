//https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solution/

class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        vector<unordered_map<long long,long long>>dp(nums.size());
        
        long long ans = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                long long diff = (long long)nums[i]-nums[j] ;
                
                ans +=dp[j][diff];
                dp[i][diff] += (dp[j][diff]+1);
                
            }
        }
        return ans;
        
    }
};
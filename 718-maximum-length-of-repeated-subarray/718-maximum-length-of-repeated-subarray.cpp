/*
Same as Longest common substirng - O(m*n)



Using Rolling hash + Binary search here is tedious task - O((M+N)*log(min(M,N))

*/
class Solution 
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        
        int maxi = 0;
        for(int i = 1;i<=nums1.size();i++)
        {
            for(int j = 1;j<=nums2.size();j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi;
        
    }
};
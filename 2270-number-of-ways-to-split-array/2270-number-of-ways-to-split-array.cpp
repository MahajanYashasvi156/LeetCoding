class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefixSum(nums.size(),0);
        
        prefixSum[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
        
        long long sum = prefixSum[prefixSum.size()-1];
        int ans = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(prefixSum[i]>=(sum-prefixSum[i]))
                ans++;
        }
        return ans;
    }
};
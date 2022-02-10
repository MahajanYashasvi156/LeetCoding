class Solution
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> prefixSum;
        int ans=0;
        int currSum=0;
        prefixSum[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            if(prefixSum.find(currSum-k)!=prefixSum.end())
                ans=ans+prefixSum[currSum-k];
            prefixSum[currSum]++;
        }
        return ans;
    }
};
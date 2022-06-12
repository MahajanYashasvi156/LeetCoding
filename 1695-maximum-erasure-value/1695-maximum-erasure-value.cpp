class Solution 
{
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int low = 0;
        int high = 0;
        unordered_map<int,int> m;
        int maxScore = 0;
        int currScore = 0;
        while(high<nums.size())
        {
            while(m[nums[high]]==1)
            {
                m[nums[low]]--;
                currScore=currScore-nums[low];
                low++;
            }
            m[nums[high]]++;
            currScore = currScore+nums[high];
            maxScore = max(maxScore,currScore);
            high++;
        }
        return maxScore;
    }
};
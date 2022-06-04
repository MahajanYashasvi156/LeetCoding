class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int maxOnes = 0;
        int zeros = 0;
        int low = 0;
        int high = 0;
        while(high<nums.size())
        {
            if(nums[high]==0 and zeros<k)
            {
                zeros++;
                high++;
            }
            else if(nums[high]==0 and zeros==k)
            {
                if(nums[low]==0)
                    zeros--;
                low++;
            }
            else
            {
                high++;
            }
            maxOnes = max(maxOnes,high-low);
        }
        return maxOnes;
    }
};
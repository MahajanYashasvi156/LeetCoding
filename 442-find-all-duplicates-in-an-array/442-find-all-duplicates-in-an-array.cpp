class Solution 
{
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        for(int i = 0;i<nums.size();i++)
        {
            while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        
        vector<int> result;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
                result.push_back(nums[i]);
        }
        return result;
    }
};
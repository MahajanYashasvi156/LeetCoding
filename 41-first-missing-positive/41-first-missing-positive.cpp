class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int i =0;
        while(i<nums.size())
        {
            if(nums[i]>0 and nums[i]-1<nums.size() and nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1],nums[i]);
            else
                i++;
        }
        
        for(int i =0;i<nums.size();i++)
        {
            if(i+1!=nums[i])
                return i+1;
        }
        return nums.size()+1;
    }
};
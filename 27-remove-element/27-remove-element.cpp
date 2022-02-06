class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        for(int i = 0;i<nums.size();)
        {
            if(nums[i]==val)
            {
                nums[i]=nums[nums.size()-1];
                nums.pop_back();
            }
            else
                i++;
        }
        return nums.size();
    }
};
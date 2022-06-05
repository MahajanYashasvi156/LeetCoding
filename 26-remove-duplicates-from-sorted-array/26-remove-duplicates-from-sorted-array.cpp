class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int prev = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]==prev)
            {
                nums[i]=INT_MAX;
            }
            else
            {
                prev = nums[i];
            }
        }

        int i = 0;
        int j = 0;
        while(j<nums.size())
        {
            if(nums[j]!=INT_MAX)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        return i;
    }
};






/*
Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
TC - O(NlogN)
SC - O(1)

If the number appears more than once, replace it with INT_MAX.
Then sort it so that valid numbers appears in the beginning.


class Solution 
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int k = nums.size();
        int prev = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==prev)
            {
                k--;
                nums[i]=INT_MAX;
            }
            else
            {
                prev=nums[i];
            }  
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};
*/
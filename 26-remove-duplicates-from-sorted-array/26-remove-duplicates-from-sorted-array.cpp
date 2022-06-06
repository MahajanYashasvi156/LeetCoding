class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i = 1; //next index of perfect array
        int j = 1;
        while(j<nums.size())
        {
            if(nums[j]!=nums[i-1])
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
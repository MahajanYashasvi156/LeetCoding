//Longest alternating subsequence

class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int up = 1;
        int down = 1;
        
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1]) //down case
                down = up+1;
            else if(nums[i]>nums[i-1]) //up case
                up = down +1;
        }
        
        return max(down,up);
    }
};
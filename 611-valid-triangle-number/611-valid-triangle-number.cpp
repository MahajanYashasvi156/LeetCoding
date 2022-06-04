class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = nums.size()-1;i>=2;i--)
        {
            int longestSide = nums[i];
            int low = 0;
            int high = i-1;
            
            while(low<high)
            {
                int sumofTwoSides = nums[low]+nums[high];
               if(longestSide<sumofTwoSides)
               {
                   count=count+high-low;
                   high--;
               }
                else
                {
                    low++;
                }
            }
        }
        return count;
    }
};
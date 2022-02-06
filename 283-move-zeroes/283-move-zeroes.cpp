/*
Link - https://leetcode.com/problems/move-zeroes/
TC - O(N^2)
SC - O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int high=nums.size()-1;
        for(int i=0;i<high;)
        {
            if(nums[i]==0)
            {
                int j;
                for(j=i;j<high;j++)
                    nums[j]=nums[j+1];
                nums[j]=0;
                high--;
            }
            else
                i++;
        }
    }
};
/*
class Solution 
{
public:
    
    void moveZeroes(vector<int>& nums) 
    {
        int lastNonZeroFound = -1;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]!=0)
           {
               lastNonZeroFound++;
               swap(nums[lastNonZeroFound],nums[i]);
           }
       }
    }
};
*/
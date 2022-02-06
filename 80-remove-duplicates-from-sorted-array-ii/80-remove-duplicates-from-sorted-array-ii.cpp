/*
Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/

TC - O(nlogn)
SC - O(1)

If the number appears more than twice , replace it with INT_MAX.
Then sort it so that valid numbers appears in the beginning.


class Solution 
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int c = 0;
        int k = nums.size();
        int v = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(c==2 and nums[i]==v)
            {
                k--;
                nums[i]=INT_MAX;
            }
            else if(nums[i]==v)
                c++;
            else
            {
                v=nums[i];
                c=1;
            }  
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count=1;
        int prev=nums[0];
        int duplicates=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==prev)
            {
                count++;
                if(count>=3)
                {
                    nums[i]=INT_MAX;
                    duplicates++;
                }
                
            }
            else
            {
                prev = nums[i];
                count=1;
            }
        }
        sort(nums.begin(),nums.end());
        return nums.size()-duplicates;
    }
};
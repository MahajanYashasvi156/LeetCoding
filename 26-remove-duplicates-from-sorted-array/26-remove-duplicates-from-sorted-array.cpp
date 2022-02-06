/*


*/
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int k = nums.size();
        int v = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==v)
            {
                k--;
                nums[i]=INT_MAX;
            }
            else
            {
                v=nums[i];
            }  
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};
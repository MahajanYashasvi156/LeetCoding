/*


*/
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
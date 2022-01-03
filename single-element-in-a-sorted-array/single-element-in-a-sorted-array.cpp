class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int low=0;
        int high=nums.size();
        int mid;
        while(low<=high)
        {
           mid=(low+high)>>1;
            //mid is even so it's duplicate must be after it.
            if(mid%2==0)
            {
                if(mid+1 <nums.size() and nums[mid]==nums[mid+1])
                {
                    low=mid+1;
                }
                else if(mid-1 >=0 and nums[mid]==nums[mid-1])
                {
                    high=mid-1;
                }
                else
                    return nums[mid];
            }
            else
            {
                if(mid-1 >=0 and nums[mid]==nums[mid-1])
                {
                    low=mid+1;
                }
                else if(mid+1 and nums[mid]==nums[mid+1])
                {
                    high=mid-1;
                }
                else
                    return nums[mid];
            }
                
        }
        return -1;
    }
};
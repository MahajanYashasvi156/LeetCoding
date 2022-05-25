class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            // For sure there will be two cases
            // Either left subarray of current position is sorted or right subarray is sorted.
            // Left subarray is sorted.
            if(nums[low]<=nums[mid])
            {
                //target lies in left sorted array so pick left subarray for search.
                if(nums[low]<=target and nums[mid]>=target)
                    high=mid-1;
                //target does not lies in left sorted array so pick right subarray for search.
                else
                    low=mid+1;
            }
            //Right subarray is sorted.
            else
            {
                //target lies in right sorted array so pick right subarray for search.
                if(nums[mid]<=target and nums[high]>=target)
                {
                    low=mid+1;
                }
                //target does not lies in right sorted array so pick left subarray for search.
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
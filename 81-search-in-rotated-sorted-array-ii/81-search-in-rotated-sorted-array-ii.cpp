class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
        
            if(nums[mid]==target)
                return true;
            if(nums[low]==nums[mid])
            {
                low++;
                continue;
            }
                
            if(nums[mid]>nums[low]) // means left part is sorted
            {
                if(nums[low]<=target and nums[mid]>=target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else 
            {
               if(nums[mid]<=target and target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return false;
    }
};
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) 
    {
        int low = 1;
        int high = nums.size()-2;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                return mid;
            if(nums[mid]>nums[mid-1])
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
};
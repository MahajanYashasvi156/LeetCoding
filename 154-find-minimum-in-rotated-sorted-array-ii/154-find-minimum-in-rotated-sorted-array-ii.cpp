class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid =  (low+high)/2;
           
            if(mid>0 and nums[mid-1]>nums[mid])
                return nums[mid];
            
            if(nums[mid]<nums[high])
                high = mid-1;
            else if(nums[mid]>nums[high])
                low = mid+1;
            else
                high--;
        }
        return nums[low];
    }
};
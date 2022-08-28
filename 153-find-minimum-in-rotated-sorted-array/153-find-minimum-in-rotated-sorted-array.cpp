class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(mid>0 and nums[mid-1]>nums[mid])
                return nums[mid];
            
            //means right part has decreasing subarray array
            if(nums[mid]>nums[high])
            {
               low = mid+1;
            }
            else 
                high = mid-1;
        }
        return nums[low]; //when first number is minimum
    }
};


/*
Points to Notice - 
    1. All the elements to the left of inflection point > first element of the array.
    2. All the elements to the right of inflection point < first element of the array.

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        int first = nums[0];
        int ans = first;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(nums[mid]>=first)
                low = mid+1;
        
            else
            {
                ans = nums[mid];
                high = mid-1;
            }
        }
        return ans;
    }
};

*/
/*
     
     Note :- Just identify which part of array is sorted and based on that make decision.
     
     1. If the left part is sorted (nums[mid]>nums[low]) then
            check whether our target can exist in that sorted left part based on range of sorted array.
            If yes then high = mid-1;
            else go to right part , low = mid+1
    
    2. If the right part is sorted
        if the target lies within the range of right sorted array then go to right else left subarray.
        
        For handling duplicates, increase the low pointer whenever low element and middle element is equal
        
        TC - O(N) //to handle duplicates
            

*/
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
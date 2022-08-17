/*
Points to Notice - 
    1. All the elements to the left of inflection point > first element of the array.
    2. All the elements to the right of inflection point < first element of the array.
*/
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
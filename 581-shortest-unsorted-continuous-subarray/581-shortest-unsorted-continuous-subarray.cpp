class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        // Pointer to the first and the last index
        int low = 0;
        int high = nums.size()-1;
        
        // Minimum number till pointer right and maximum number till pointer left
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        // Indices of current unsorted sub-array
        int start = -1;
        int end =  -1;
        
        // Repeat until high reaches 0 and low eventually reaches n-1
        while(low<nums.size())
        {
             /* If current number {nums[low]} is lesser than {max} encountered till 
            left, then current number {nums[low]} is not in sorted position, */
            
            if(nums[low]<maxi)
            {
                end = low; 
            }
            // Else current number {nums[low]} is the {max} till left
            else
            {
                 maxi = nums[low];
            }
            
            /* If current number {nums[right]} is greater than {min} encountered
            till right, then current number {nums[right]} is not in sorted position */
            
            if(nums[high]>mini)
            {
                start = high;
            }
            // Else current number {nums[right]} is the {min} till right
                
            else
            {
               mini = nums[high];
            }
            high--;
            low++;
        }
        /* If any of the start or end is -1, then the array is sorted already, return 0.
         else return the size of the sub array */
        
        return start!=-1 ? end - start+1:0;
        
    }
};
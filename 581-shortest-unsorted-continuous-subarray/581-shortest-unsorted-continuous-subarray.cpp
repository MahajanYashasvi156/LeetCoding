class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int start = -1;
        int end =  -1;
        
        while(low<nums.size())
        {
            if(nums[low]<maxi)
            {
                end = low; 
            }
            else
            {
                 maxi = nums[low];
            }
            
            if(nums[high]>mini)
            {
                start = high;
            }
            else
            {
               mini = nums[high];
            }
            high--;
            low++;
        }
        return start!=-1 ? end - start+1:0;
        
    }
};
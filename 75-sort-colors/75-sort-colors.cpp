class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int left=0;
        int right=nums.size()-1;
        //Left - All elements to left of left are 0 .
        //right -All elements to right of right are 2.
        //ptr- Linearly iterate till the right.
        //All elements to the left of ptr are either 1 or 0.
        for(int ptr=0;ptr<=right;)
        {
            if(nums[ptr]==0)
            {
                swap(nums[left],nums[ptr]);
                left++;
                ptr++;
            } 
            else if (nums[ptr]==2)
            {
                swap(nums[right],nums[ptr]);
                right--;
            }
            else 
                ptr++;
            
        }
    }
};
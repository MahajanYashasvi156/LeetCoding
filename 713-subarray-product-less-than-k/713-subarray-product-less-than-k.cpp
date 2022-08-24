class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if(k==0)
            return 0;
        int low = 0;
        int high = 0;
        
        long long prod = 1;
        int ans = 0;
        while(high<nums.size())
        {
            prod = prod*nums[high];
            
            while(low<=high and prod>=k)
            {
                prod = prod / nums[low];
                low++;
            }
            
            ans = ans + high - low+1;
            high++;
        }
        return ans;
    }
};
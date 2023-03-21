class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        
        int i = 0;
        int j = 0;
        
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                ans = ans + (j-i+1);
            }
            else
            {
                i = j+1;
            }
             j++;
        }
        return ans;
    }
};
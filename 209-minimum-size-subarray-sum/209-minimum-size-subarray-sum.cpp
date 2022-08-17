class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefixSum;
        
        prefixSum.push_back(0);
        prefixSum.push_back(nums[0]);
        if(nums[0]>=target)
            return 1;
        int ans = INT_MAX;
        for(int i = 1;i<n;i++)
        {
            int newSum = nums[i]+prefixSum[i];
            prefixSum.push_back(newSum);
            
            if(newSum>=target)
            {
                int need = newSum-target;
                
                int index = upper_bound(prefixSum.begin(),prefixSum.end(),need) -prefixSum.begin() ;
                
                index--;
                ans = min(ans,i-index+1);
            }
        }
        
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            if(i>0 and nums[i]==nums[i-1])
                continue;
            int low = i+1;
            int high = nums.size()-1;
            while(low<high)
            {
                int sum = nums[i]+nums[low]+nums[high];
                if(sum==0)
                {
                    result.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                    while(low<high and nums[low-1]==nums[low]) low++;
                }
                else if(sum>0)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        
        return result;
    }
};
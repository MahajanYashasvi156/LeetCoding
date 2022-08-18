class Solution 
{
    vector<int> LIS(vector<int>& nums)
    {
        vector<int> result ;
        vector<int> ans(nums.size(),0);
        for(int i = 0;i<nums.size()-1;i++)
        {
            int index = lower_bound(result.begin(),result.end(),nums[i]) - result.begin();
            
            if(index==result.size())
                result.push_back(nums[i]);
            else
                result[index] = nums[i];
            ans[i] = index;
        }
   
        return ans;
    }
    
    vector<int> LDS(vector<int>& nums)
    {
        vector<int> ans(nums.size(),0);
        vector<int> result ;
        
        for(int i = nums.size()-1;i>=0;i--)
        {
            int index = lower_bound(result.begin(),result.end(),nums[i]) - result.begin();
            
            if(index==result.size())
                result.push_back(nums[i]);
            else
                result[index] = nums[i];
            ans[i] = index;
        }
         
        return ans;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        
        vector<int> lis;
        vector<int>lds;
        lis = LIS(nums);
        lds=LDS(nums);
        
       
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 1;i<n;i++)
        {
            if(lis[i] and lds[i])
            ans = min(ans , n-(lis[i]+lds[i]+1));
        }
        return ans;
    }
};
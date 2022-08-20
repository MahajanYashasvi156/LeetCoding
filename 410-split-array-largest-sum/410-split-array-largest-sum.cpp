class Solution
{
    bool check(vector<int>&nums,int m,int maxSum)
    {
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>maxSum)
                return false;
            if(sum+nums[i]<=maxSum)
                sum = sum + nums[i];
            else
            {
                sum = nums[i];
                m = m-1;
            }
            if(m==0)
                return false;
        }
        
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int low = 0;
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = INT_MAX;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(check(nums,m,mid))
            {
                high = mid-1;
                ans = mid;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
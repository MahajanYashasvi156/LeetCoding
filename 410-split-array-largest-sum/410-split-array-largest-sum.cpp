class Solution
{
    bool check(vector<int>&nums,int m,int maxSum)
    {
        int sum = 0;
        int i = 0;
        while(i<nums.size())
        {
            if(nums[i]>maxSum)
                return false;
            if(sum+nums[i]<=maxSum)
            {
                sum = sum + nums[i];
            }
            else
            {
                if(m==1)
                    return false;
                sum = nums[i];
                m = m-1;
            }
            i++;
        }
        
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int low = 0;
        int high = INT_MAX;
        
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
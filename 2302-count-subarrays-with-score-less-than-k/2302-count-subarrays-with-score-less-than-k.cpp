class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int low = 0;
        int high = 0;

        long long ans = 0;
        int n = nums.size();
        long long sum = 0;
        
        while(high<n)
        {
            sum +=nums[high];

            int len = high-low+1;

            long long score = sum*len;
            while(score>=k)
            {
                sum = sum - nums[low];
                low++;
                len--;
                score = sum*len;
            }
            ans = ans+ high-low+1;
            high++;
        }
        return ans; 
    }
};
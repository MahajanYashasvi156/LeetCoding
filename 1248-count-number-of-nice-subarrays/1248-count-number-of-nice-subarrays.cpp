class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]%2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        // mp[0]=1;
        for(int i =0;i<nums.size();i++)
        {
            sum = sum +nums[i];
            if(sum==k)
                count++;
            if(mp.find(sum-k)!=mp.end())
            {
                count = count + mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};
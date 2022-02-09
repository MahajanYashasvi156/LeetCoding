class Solution 
{
public:
    int findPairs(vector<int>& nums, int k) 
    {
        map<int,bool> mp;
        int kDiffUniquePair=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                if(mp.find(nums[i]-k)!=mp.end()) 
                    kDiffUniquePair++;
                if(mp.find(nums[i]+k)!=mp.end())
                    kDiffUniquePair++;
      
                mp[nums[i]]=false;
            }
            else if(k==0 and mp[nums[i]]==false)
            {
                mp[nums[i]]=true;
                kDiffUniquePair++;
            }
        }
        return kDiffUniquePair;
    }
};
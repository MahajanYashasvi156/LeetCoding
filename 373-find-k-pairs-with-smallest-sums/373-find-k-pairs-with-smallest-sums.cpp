class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<pair<int,pair<int,int>>> maxheap;
        
        for(int i = 0;i<nums1.size();i++)
        {
            if(maxheap.size()==k and nums1[i]+nums2[0]>=maxheap.top().first) 
                break;
            for(int j = 0; j<nums2.size();j++)
            {
                int sum = nums1[i]+nums2[j];
                if(maxheap.size()<k)
                {
                    maxheap.push({sum,{nums1[i],nums2[j]}});
                }
                else
                {
                    if(maxheap.top().first>sum)
                    {
                        maxheap.pop();
                        maxheap.push({sum,{nums1[i],nums2[j]}});
                    }
                }
            }
        }
        vector<vector<int>> result;
        while(!maxheap.empty())
        {
            result.push_back({maxheap.top().second.first,maxheap.top().second.second});
            maxheap.pop();
        }
        return result;
    }
};
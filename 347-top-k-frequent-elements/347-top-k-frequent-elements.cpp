/*
TC - O(n)
SC - O(k+n)
*/
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> result;
        unordered_map<int,int> fm ;
        for(int i=0;i<nums.size();i++)
        {
            fm[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it = fm.begin();it!=fm.end();it++)
        {
            pq.push({it->second,it->first});
            if(pq.size()>k)
                pq.pop();
        }
        while(pq.empty()==false)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        
    }
};
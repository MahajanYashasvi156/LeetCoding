class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int,int>> effSpeed;
        
        for(int i = 0;i<n;i++)
        {
            effSpeed.push_back({efficiency[i],speed[i]});
        }
        
        sort(effSpeed.begin(),effSpeed.end(),greater<pair<int,int>>());
        
        priority_queue<int,vector<int>,greater<int>> minHeap;
        long long speedSum = 0;
        int M = 1000000007;
        long long ans = INT_MIN;
        for(int i = 0;i<k;i++)
        {
            minHeap.push(effSpeed[i].second);
            speedSum+=effSpeed[i].second;
            ans = max(ans,speedSum*effSpeed[i].first);
        }
        
        for(int i = k;i<n;i++)
        {
            if(minHeap.top()<effSpeed[i].second)
            {
                speedSum-=minHeap.top();
                minHeap.pop();
                speedSum+=effSpeed[i].second;
                minHeap.push(effSpeed[i].second);
                ans = max(ans,speedSum*effSpeed[i].first);
            }
            
        }
        return ans%M;
    }
};
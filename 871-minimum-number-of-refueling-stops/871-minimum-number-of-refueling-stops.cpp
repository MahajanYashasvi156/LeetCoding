class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int maxReach = startFuel;
        priority_queue<int,vector<int>> maxHeap;
        
        int i = 0;
        int ans = 0;
        
        while(maxReach<target)
        {
            while(i<stations.size() and stations[i][0]<=maxReach)
            {
                maxHeap.push(stations[i][1]);
                i++;
            }
            if(maxHeap.empty())
                return -1;
           
            maxReach = maxReach + maxHeap.top();
            maxHeap.pop();
            ans++;
            
        }
        return ans;
    }
};
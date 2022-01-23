class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> distance(n+1,INT_MAX);
        for(auto a: times)
        {
            int start = a[0];
            int end = a[1];
            int weight = a[2];
            
            adj[start].push_back({end,weight});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        
        distance[k]=0;
        
        minheap.push({0,k});
        
        while(!minheap.empty())
        {
           int node = minheap.top().second;
            minheap.pop();
            
            for(auto a : adj[node])
            {
                int end = a.first;
                int weight = a.second;
                
                if(distance[end]>(distance[node]+weight))
                {
                    distance[end]=distance[node]+weight;
                    
                    minheap.push({distance[end],end});
                }
            }
        }
        
        int delay =INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(distance[i]==INT_MAX)
                return -1;
            delay= max(delay,distance[i]);
            
        }
        return delay;
        
    }
};
class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                 int cost = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                 adj[i].push_back({j,cost});
                 adj[j].push_back({i,cost});
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        vector<int> nodeWeight(n,INT_MAX);
        vector<int> visited(n,0);
        minHeap.push({0,0});
        nodeWeight[0]=0;
        int minCost=0;

       while(!minHeap.empty())
        {
            int src = minHeap.top().second;
            int cost = minHeap.top().first;
            minHeap.pop();
           if(visited[src]==1)
               continue;
            minCost +=cost;
            visited[src]=1;
            for(auto a:adj[src])
            {
                int dest=a.first;
                int weight = a.second;
                if(visited[dest]==0 and nodeWeight[dest]>weight)
                {
                    nodeWeight[dest] =weight;
                    minHeap.push({nodeWeight[dest],dest});
                }
            }
            
        }
        return minCost;
    }
};
class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        
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
            for(int dest=0;dest<n;dest++)
            {
                if(dest==src)
                    continue;
                int weight = abs(points[src][0]-points[dest][0]) + abs(points[src][1]-points[dest][1]);
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
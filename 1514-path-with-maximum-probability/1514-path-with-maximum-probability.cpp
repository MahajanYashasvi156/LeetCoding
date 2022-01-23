class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        priority_queue<pair<int,double>> maxHeap;
        vector<vector<pair<int,double>>> adj(n);
        vector<double> distance(n,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        maxHeap.push({1,start});
        distance[start] =1;
        while(!maxHeap.empty())
        {
            int source = maxHeap.top().second;
            maxHeap.pop();
            for(auto a: adj[source])
            {
                int dest = a.first;
                double prob = a.second;
                
                if(distance[dest]<(distance[source]*prob))
                {
                    distance[dest]=distance[source]*prob;
                    maxHeap.push({distance[dest],dest});
                }
            }
        }
        return distance[end];
    }
};
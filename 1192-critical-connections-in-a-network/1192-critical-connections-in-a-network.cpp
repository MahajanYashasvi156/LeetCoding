class Solution 
{
    void DFS(int u,vector<vector<int>>&graph,vector<int>&low,vector<int>&disc,vector<int>&parent, vector<vector<int>> &bridges)
    {
        static int time = 0;
        
        disc[u] = time;
        low[u] = time;
        
        time = time +1;
        
        for(int v : graph[u])
        {
            if(disc[v]==-1)
            {
                parent[v] = u;
                DFS(v,graph,low,disc,parent,bridges);
                low[u] = min(low[u],low[v]);
                
                if(low[v]>disc[u])
                    bridges.push_back({u,v});
            }
            else if(v!=parent[u])
            {
                low[u] = min(low[u],disc[v]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<int>low(n,-1);
        vector<int> disc(n,-1);
        vector<int> parent(n,-1);
        vector<vector<int>> bridges;
        
        vector<vector<int>> graph(n);
        
        for(auto a: connections)
        {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        
        DFS(0,graph,low,disc,parent,bridges);
        return bridges;
    }
};
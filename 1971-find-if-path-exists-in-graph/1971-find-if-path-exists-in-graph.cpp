class Solution 
{
    int dfs(int src,int dst,vector<vector<int>> &graph,vector<int>&visited)
    {
        if(src==dst)
            return 1;

        visited[src]=1;

        for(int neighbour:graph[src])
        {
            if(visited[neighbour]==0)
            {
                if(dfs(neighbour,dst,graph,visited)==1)
                    return 1;
            }
        }
        return 0;
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> graph(n+1);
        for(auto a:edges)
        {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        vector<int>visited(n+1,0);
        return dfs(source,destination,graph,visited);
    }
};
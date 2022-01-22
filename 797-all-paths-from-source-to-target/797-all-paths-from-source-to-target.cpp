class Solution 
{
    void dfs(int src, vector<int>& visited,vector<vector<int>>& graph, vector<vector<int>>&allPath,vector<int>&path,int n )
    {
        path.push_back(src);
        
        if(src==n-1)
        {
            allPath.push_back(path);
            path.pop_back();
            return ;
        }
        
        visited[src]=1;
        
        for(int dest : graph[src])
        {
            if(visited[dest]==0)
            {
                dfs(dest,visited,graph,allPath,path,n);
            }
        }
        path.pop_back();
        visited[src]=0;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<vector<int>> allPath;
        vector<int> path;
        dfs(0,visited,graph,allPath,path,n);
        return allPath;
    }
};
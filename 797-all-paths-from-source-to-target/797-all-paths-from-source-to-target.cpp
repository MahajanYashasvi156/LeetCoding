class Solution 
{
    void dfs(int src,int dest, vector<int>& visited,vector<vector<int>>& graph, vector<vector<int>>&allPath,vector<int>&path)
    {
        path.push_back(src);
        
        if(src==dest)
        {
            allPath.push_back(path);
            path.pop_back();
            return ;
        }
        
        visited[src]=1;
        
        for(int end : graph[src])
        {
            if(visited[end]==0)
            {
                dfs(end,dest,visited,graph,allPath,path);
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
        dfs(0,n-1,visited,graph,allPath,path);
        return allPath;
    }
};
/*
Link - https://leetcode.com/problems/all-paths-from-source-to-target/submissions/

TC - O(V+E)
SC - O(V)
*/

class Solution 
{
    void dfs(int src,int dest,vector<vector<int>>& graph, vector<vector<int>>&allPath,vector<int>&path)
    {
        path.push_back(src);
        
        if(src==dest)
        {
            allPath.push_back(path);
            path.pop_back();
            return ;
        }
         
        for(int end : graph[src])
        {
            dfs(end,dest,graph,allPath,path);   
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<vector<int>> allPath;
        vector<int> path;
        dfs(0,n-1,graph,allPath,path);
        return allPath;
    }
};
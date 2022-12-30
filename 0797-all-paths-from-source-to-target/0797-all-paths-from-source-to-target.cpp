/*
Link - https://leetcode.com/problems/all-paths-from-source-to-target/submissions/

TC - O(VE)
SC - O(1)
ASC - O(V)

Here , the given graph is DAG i.e. there is no cycle so no need of visited here. 

If we want to find all paths then if it is not DAG then before leaving a node we have to set it unvisited so that we can reach to that node again by some other path. So the purpose of visited in this case is to make sure in same dfs call the same node should not come more than once(all nodes in the path are unique) i.e. if there is cycle we have to avoid that. 
But in DAG there will not be cycle so no need to maintain visited.

In nutshell,
Make a node unvisited as we have to reach to it from other path. We don't do this in normal DFS as we dont want to visit a node again
Now, this is a DAG - which don't have cycle, so visited is not needed here.
If the graph might had cycle, then we would have used visited array as described in the first line(making node unvisited before living) and also for not falling in cycle.

 
Approach 1 - For any graph.
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
*/

/*
Approach - 2 for DAG
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
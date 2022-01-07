class Solution 
{
    bool dfsCheck(vector<vector<int>> &adj,vector<int> &status,int src)
    {
        status[src]=1;
        
        for(int dest : adj[src])
        {
            if(status[dest]==1)
                return false;
            if(status[dest]==0)
            {
                if(dfsCheck(adj, status,dest)==false)
                    return false;
            }
        }
        
        status[src]=2;
        return true;
    }
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> status(numCourses,0);
        
        for(auto edge : prerequisites)
        {
            int start = edge[0];
            int end = edge[1];
            adj[start].push_back(end);
        }
        for(int src = 0;src< numCourses;src++)
        {
            if(status[src]==0)
            {
                if(dfsCheck(adj, status,src)==false)
                    return false;
            }
        }
        return true;
    }
};
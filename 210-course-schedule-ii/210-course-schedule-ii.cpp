class Solution 
{
    bool topoDFS(int src,int numCourses,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &localvis,stack<int>&s)
    {
        localvis[src]=true;
        visited[src]=true;
        
        for(int dest:adj[src])
        {
            if(visited[dest]==false)
            {
                if(topoDFS(dest,numCourses,adj,visited,localvis,s)==false)
                    return false;
            }
            else if(localvis[dest]==true)
                return false;
            
        }
        s.push(src);
        localvis[src]=false;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        vector<bool> localvis(numCourses,false);
        stack<int>s;
        vector<int> order;
        
        //Directed Graph.
        for(auto list:prerequisites)
        {
            int start = list[1];
            int end = list[0];
            adj[start].push_back(end);
        }
        for(int src=0;src<numCourses;src++)
        {
            if(visited[src]==false)
            {
                if(topoDFS(src,numCourses,adj,visited,localvis,s)==false)
                    return order;
            }  
        }
        
        while(!s.empty())
        {
            order.push_back(s.top());
            s.pop();
        }
        return order;
    }
};
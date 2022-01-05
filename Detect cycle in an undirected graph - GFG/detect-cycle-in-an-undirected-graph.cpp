// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
  public:
    
    bool checkCycleUsingDFSIterative(int source,vector<int> adj[],vector<bool> &visited)
    {
        stack<pair<int,int>> s;//child,parent.
        s.push({source,-1});
        
        while(!s.empty())
        {
            int start  = s.top().first;
            int parent = s.top().second;
            s.pop();
            
            //Already not explored then only explore that vertex.
            if(visited[start]==false)
            {
                visited[start]=true;
                for(int end : adj[start])
                {
                    if(visited[end]==false)
                    {
                        s.push({end,start});
                    }
                    else if(end!=parent)
                        return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V);
        
        for(int source=0;source<V;source++)
        {
            if(visited[source]==false)
            {
                if(checkCycleUsingDFSIterative(source,adj,visited))
                    return true;
            }
        }
        return false;
    }
};

/*
/*
Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

Same for all three Approach.
TC - O(V+E)
SC - O(V)

Approach - 1 BFS Using Iteration

Apply BFS to detect cycle in an undirected graph.

As we know, in BFS we use visited array to not visit a node again and to avoid infinite loop

So in our approach, for an undirected graph we have to maintain parent of the node.

In BFS if the visited node again appears as the ajacent node during traversal and this node is not the parent node then there is a cycle.



class Solution 
{
  public:
    
    bool checkCycle(int src,vector<int> adj[],vector<bool> &visited)
    {
        queue<pair<int,int>> q; //queue(child,par)
        
        visited[src]=1;
        q.push({src,-1});
        
        while(!q.empty())
        {
            int start=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(int end:adj[start])
            {
                if(visited[end]==false)
                {
                    visited[end]=true;
                    q.push({end,start});
                }
                //end node already visited and it is not start's parent, so cycle detected
                else if(end!=parent)
                    return true;
            }
        }
        //Cycle not detected in this component.
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V);
        //Since given graph can be disconnected. Call for all unviisted node so far considering it as src.
        for(int src=0;src<V;src++)
        {
            if(visited[src]==false)
            {
                //It will execute for single component and set visited for all nodes in that component.
                //If cycle found in any component then return true.
                if(checkCycle(src,adj,visited))
                    return true;
            }
        }
        return false;
    }
};

/*
Approach - 2  Using DFS Recursion

TC - O(V+E)
SC - O(V)
Aux SC - O(V)

class Solution 
{
  public:
    
    bool checkCycleUsingDFS(int source,int parent,vector<int> adj[],vector<bool> &visited)
    {
        visited[source]=true;
        for(int destination:adj[source])
        {
            if(visited[destination]==false)
            {
                if(checkCycleUsingDFS(destination,source,adj,visited))
                    return true;
            }
            else if (destination!=parent)
                return true;
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V);
        
        for(int source=0;source<V;source++)
        {
            if(visited[source]==false)
            {
                if(checkCycleUsingDFS(source,-1,adj,visited))
                    return true;
            }
        }
        return false;
    }
};

/*
Approach - 3 Using DFS Iteration

TC - O(V+E)
SC - O(V)


class Solution 
{
  public:
    
    bool checkCycleUsingDFSIterative(int source,vector<int> adj[],vector<bool> &visited)
    {
        stack<pair<int,int>> s;//child,parent.
        s.push({source,-1});
        
        while(!s.empty())
        {
            int start  = s.top().first;
            int parent = s.top().second;
            s.pop();
            
            //Already not explored then only explore that vertex.
            if(visited[start]==false)
            {
                visited[start]=true;
                for(int end : adj[start])
                {
                    if(visited[end]==false)
                    {
                        s.push({end,start});
                    }
                    else if(end!=parent)
                        return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V);
        
        for(int source=0;source<V;source++)
        {
            if(visited[source]==false)
            {
                if(checkCycleUsingDFSIterative(source,adj,visited))
                    return true;
            }
        }
        return false;
    }
};


*/
// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
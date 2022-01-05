// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
  public:
    
    bool checkCycle(int source,int parent,vector<int> adj[],vector<bool> &visited)
    {
        visited[source]=true;
        for(int destination:adj[source])
        {
            if(visited[destination]==false)
            {
                if(checkCycle(destination,source,adj,visited))
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
                if(checkCycle(source,-1,adj,visited))
                    return true;
            }
        }
        return false;
    }
};

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
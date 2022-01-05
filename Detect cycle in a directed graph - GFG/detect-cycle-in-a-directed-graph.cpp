// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
  public:
   bool checkCycleDFS(int src,vector<int> adj[],vector<bool>&visited,vector<bool>&dfsVisited)
   {
       visited[src]=1;
       dfsVisited[src]=1;
       for(int start:adj[src])
       {
           if(visited[start]==false)
           {
                if(checkCycleDFS(start,adj,visited,dfsVisited))
                    return true;
           }
           else if(dfsVisited[start]==true)
                return true;
       }
       dfsVisited[src]=0;
       return false;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V);
        vector<bool> dfsVisited(V);
        
        for(int src=0;src<V;src++)
        {
            if(visited[src]==false)
            {
                if(checkCycleDFS(src,adj,visited,dfsVisited))
                    return true;
            }
            
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
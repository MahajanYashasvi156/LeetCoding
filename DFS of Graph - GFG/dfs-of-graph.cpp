// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsPreorder(int V, int src, vector<int> adj[],vector<int> &dfsTraversal,vector<int> &visited)
    {
        dfsTraversal.push_back(src);
        visited[src]=1;
        
        for(int dst:adj[src])
        {
            if(visited[dst]==0)
                dfsPreorder(V,dst,adj,dfsTraversal,visited);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> dfsTraversal;
        vector<int> visited(V,0);
        int src=0;
        dfsPreorder(V,src,adj,dfsTraversal,visited);
        
        return dfsTraversal;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
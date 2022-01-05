// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
  public:
    bool checkCycle(int src,vector<int> adj[],vector<bool> &visited)
    {
        queue<pair<int,int>> q; //queue(child,par)
        visited[src]=1;
        q.push({src,-1});
        pair<int,int> node;
        
        while(!q.empty())
        {
            node=q.front();
            int start=node.first;
            int parent=node.second;
            q.pop();
            for(int end:adj[start])
            {
                if(visited[end]==false)
                {
                    visited[end]=true;
                    q.push({end,start});
                }
                else if(end!=parent)
                    return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V);
        for(int src=0;src<V;src++)
        {
            if(visited[src]==false)
            {
                if(checkCycle(src,adj,visited))
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
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    /*
    Link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#
    TC - O(V+E) //All nodes are traversed only once as we are maintaining visited array
    SC- O(V)
    
    Approach - It is just a level order traversal, but while pushing to the queue, check if a node is not visited already 
    And before pushing to queue make it visited.
    By doing this we ensuring each node will only be pushed once in the queue.
    */
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> result;
        vector<int>visited(V,0);
        visited[0]=1;
        q.push(0);
        int src;
        while(!q.empty())
        {
            src=q.front();
            result.push_back(src);
            q.pop();
            
            for(int dst: adj[src])
            {
                if(visited[dst]==0)
                {
                    visited[dst]=1;
                    q.push(dst);
                }
            }
            
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
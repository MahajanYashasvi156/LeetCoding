// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    /*
    Link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
    
    TC - O(V + E)
    Aux SC - O(V)
    SC - O(V)
    
    Approach - Call recursively on the first child.
    
    Maintain visited array so every node will be visited exactly once
    Only call recursively on a child if it is not visited and set it visited before making call to the child.

   */
    /*
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
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> dfsTraversal;
        vector<int> visited(V,0);
        int src=0;
        dfsPreorder(V,src,adj,dfsTraversal,visited);
        
        return dfsTraversal;
    }
     */
     
     /*
    Appraoch 2 - Iterative 
    TC - O(V + E)
    SC - O(V)
    */

    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> dfsTraversal;
        vector<int> visited(V,0);
        int src=0;
    
        stack<int> s;
        s.push(src);
        
        while(!s.empty())
        {
            src=s.top();
            s.pop();
            
            //If not already visited then only explore that node.
            if(visited[src]!=1)
            {
                visited[src]=1;
                dfsTraversal.push_back(src);
                for(auto dst=adj[src].rbegin();dst!=adj[src].rend();dst++)
                {
                    if(visited[*dst]==0)
                        s.push(*dst);
                }
            }
        }
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
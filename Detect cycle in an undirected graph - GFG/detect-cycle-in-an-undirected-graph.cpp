// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
  public:
    /*
    Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
    
    TC - O(V+E)
    SC - O(V)
    
    Approach - Apply BFS to detect cycle in an undirected graph.
    
    As we know, in BFS we use visited array to not visit a node again and to avoid infinite loop
    
    So in our approach, for an undirected graph we have to maintain parent of the node.
    
    In BFS if the visited node again appears as the ajacent node during traversal and this node is not the parent node then there is a cycle.
    */
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
        //Cycle not detected.
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
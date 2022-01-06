// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dFS(vector<int> adj[],int src,vector<bool> &visited,stack<int>&s)
	{
	    visited[src]=1;
	    for(int dest:adj[src])
	    {
	        if(visited[dest]==false)
	        {
	             dFS(adj,dest,visited,s);
	        }
	    }
	    s.push(src);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   stack<int> s;
	   vector<int> result;
	   vector<bool> visited(V+1);
	   for(int src=0;src<V;src++)
	   {
	       if(visited[src]==false)
	            dFS(adj,src,visited,s);
	   }
	   while(!s.empty())
	  {
	      result.push_back(s.top());
	      s.pop();
	  }
	   return result;
	}
	
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
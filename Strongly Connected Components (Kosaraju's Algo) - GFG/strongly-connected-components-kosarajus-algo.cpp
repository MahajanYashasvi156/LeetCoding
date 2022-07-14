// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void dfs(int src,stack<int>&s,vector<int> &visited,vector<int>adj[])
    {
        if(visited[src])
            return;
        
        visited[src]= 1;
        
        for(int n: adj[src])
        {
            dfs(n,s,visited,adj);
        }
        s.push(src);
    }
    
    void dfsComponents(int src , stack<int>&s,vector<int>&visited,vector<vector<int>>&transGraph,int &components)
    {
        visited[src] = 1;
        for(int n:transGraph[src])
        {
            if(visited[n]==0)
                dfsComponents(n,s,visited,transGraph,components);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>s;
        
        vector<int> visited(V,0);
        
        for(int i = 0;i<V;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,s,visited,adj);
            }
        }
        
        
        vector<vector<int>> transGraph(V);
        
        for(int i = 0;i<V;i++)
        {
            for(int j = 0;j<adj[i].size();j++)
            {
                transGraph[adj[i][j]].push_back(i);
            }
        }
        
        fill(visited.begin(),visited.end(),0);
        
        int components = 0;
        while(!s.empty())
        {
            int src = s.top();
            s.pop();
            if(visited[src]==0)
            {
                components++;
                dfsComponents(src,s,visited,transGraph,components);
            }
        }
        return components;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
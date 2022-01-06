// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    int minWeightNode(vector<int> &nodeWeight,vector<bool> &visited)
    {
        int minWeight=INT_MAX;
        int pos = -1;
        for(int i=0;i<nodeWeight.size();i++)
        {
            if(minWeight>nodeWeight[i] and visited[i]==false)
            {
                minWeight=nodeWeight[i];
                pos=i;
            }
        }
        return pos;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> visited(V,false);
        vector<int> nodeWeight(V,INT_MAX);
        nodeWeight[0]=0;
        
        int minSTCost=0;
        
        while(V--)
        {
           int node=minWeightNode(nodeWeight,visited);
           visited[node]=true;
           minSTCost+=nodeWeight[node];
           for(auto it : adj[node])
           {
               if(visited[it[0]]==false)
                    nodeWeight[it[0]]=min(nodeWeight[it[0]],it[1]);
           }
        }
        
        return minSTCost;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
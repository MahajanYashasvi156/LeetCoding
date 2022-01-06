// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

/*
Link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

TC - O(V^3) or O(VE)

Detailed expression - V * (V + E) = O(VE) = O(V^3)

SC - O(V)

source - {{dest,weight},{dest,weight}}

so if 1 and 2 are adjacent to 0 node then
0 - {1, 12}, {2, 15}
*/

class Solution
{
    
    int minWeightNode(vector<int> &nodeWeight,vector<bool> &visited)
    {
        int minWeight=INT_MAX;
        int pos = -1;
        for(int i=0;i<nodeWeight.size();i++)
        {
            if(visited[i]==false and minWeight>nodeWeight[i])
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
        
        //Setting first node's distance as 0 to start the algo
        nodeWeight[0]=0;
        
        int minSTCost=0;
        
        while(V--)
        {
           //Finding node at minimum distance from visited nodes.
           int source=minWeightNode(nodeWeight,visited);
           
           //marking the node visited 
           visited[source]=true;
           //adding the edge wt to that node in total cost
           minSTCost+=nodeWeight[source];
           
            //Relaxing the edges to adjacent nodes
            //Relaxing means, if a adjacent node can be reached from current vertex in lesser distance
            //than the already stored distance, then update the distance of adjancent node in nodeWeight.
           for(auto dest : adj[source])
           {
               if(visited[dest[0]]==false)
                    nodeWeight[dest[0]]=min(nodeWeight[dest[0]],dest[1]);
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
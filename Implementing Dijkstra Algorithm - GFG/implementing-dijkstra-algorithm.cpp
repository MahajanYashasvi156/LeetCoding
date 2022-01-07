// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int pickMinDistanceVertex(int V,vector<int> &distance,vector<bool> &visited)
    {
        int vertex = -1;
        int minDistance =INT_MAX;
        for(int i = 0 ;i<V ; i++)
        {
            if(visited[i]==false and distance[i]<minDistance)
            {
                vertex = i;
                minDistance = distance[i];
            }
        }
        return vertex;
    }
    
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V,INT_MAX);
        vector<bool> visited(V);
        
        //Setting source node's distance as 0 to start the algo
        distance[S]=0;
        
        int source;
        
        for(int i=0;i<V;i++)
        {
            //Finding node at minimum distance from visited nodes
            source = pickMinDistanceVertex(V,distance, visited);
            
            //marking the node visited.
            //this means its min distance from start node is finalized
            visited[source] = true;
            
            //Relaxing the edges to adjacent nodes
            //Relaxing means, if a adjacent node can be reached through current vertex in lesser distance
            //than the already stored distance, then update the distance of adjancent node in distance array
            for(auto list : adj[source])
            {
                int dest = list[0];
                int weight= list[1];
                
                if(visited[dest] ==false and distance[dest]>(distance[source]+weight))
                    distance[dest]=distance[source]+weight;
            }
        }
        //distances array is having shortest distance from source node to all the vertices
        return distance;
    }
};
/*
Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#

Dijkstra's Algorithm - To find shortest distance of all vertex from source vertex
Algo is slight modification of prims
TC - O(V^2)
SC - O(V)

Here, in distance array implementation, we will need visited array otherwise while picking minimum from distance array it will 
always pick source vertex whose distance is 0.

But in min heap implementation, while picking minimum we will pop the node(node,weight pair), so we will not need visited array
*/

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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
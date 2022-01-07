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
        
        distance[S]=0;
        
        int source;
        
        for(int i=0;i<V;i++)
        {
            source = pickMinDistanceVertex(V,distance, visited);
            visited[source] = true;
            for(auto list : adj[source])
            {
                int dest = list[0];
                int weight= list[1];
                if(visited[dest] ==false and distance[dest]>(distance[source]+weight))
                    distance[dest]=distance[source]+weight;
            }
        }
        return distance;
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
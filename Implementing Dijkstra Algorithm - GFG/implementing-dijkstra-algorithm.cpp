// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int minWeightNode(vector<int> &distance,vector<bool> &visited)
    {
        int minWeight=INT_MAX;
        int pos = -1;
        for(int i=0;i<distance.size();i++)
        {
            if(visited[i]==false and minWeight>distance[i])
            {
                minWeight=distance[i];
                pos=i;
            }
        }
        return pos;
    }
    
	public:
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool> visited(V,false);
        vector<int> distance(V,INT_MAX);
        
        //Setting source node's distance as 0 to start the algo
        distance[S]=0;
        
        while(V--)
        {
           //Finding node at minimum distance from visited nodes.
           int source=minWeightNode(distance,visited);
           
           //marking the node visited 
           visited[source]=true;
           
            //Relaxing the edges to adjacent nodes
            //Relaxing means, if a adjacent node can be reached from current vertex in lesser distance
            //than the already stored distance, then update the distance of adjancent node in distance.
           for(auto dest : adj[source])
           {
               if(visited[dest[0]]==false)
                    distance[dest[0]]=min(distance[dest[0]],distance[source]+dest[1]);
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
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
  private:
    bool bfsTopoSort(vector<int> adj[], vector<int> &visited, queue<int> &nodes, vector<int> &indegree){
        
        
        
        //Performing BFS traversal with a modification, 
		//while traversing adjacent nodes,decrementing their indegrees(as if we removing the edge)
        //if indegree became 0, then marking it visited and pushing it to our queue
        //So modified BFS where node is called visited when the node have 0 indegree 
        int source;
        while(!nodes.empty()){
            source = nodes.front();
            nodes.pop();
            
            for(int dest: adj[source]){
                
                if(visited[dest]==0){
                    indegree[dest]--;
                    if(indegree[dest]==0){
                        visited[dest]=1;
                        nodes.push(dest);
                    }    
                }
            }
        }
        for(int node: visited)
        {
            if(node==0)
                return true;
        }
	    return false;
    }
public:
    bool isCyclic(int V, vector<int> adj[]) {
        
	    vector<int> indegree(V,0);
	    queue<int> nodes;
	    vector<int> visited(V,0);
	    
	    //Calculating indegrees(no of incoming edges) of all vertices
	    for(int source = 0; source<V; source++){
	        for(int dest: adj[source])
	            indegree[dest]++;
	    }
	    
	    //If indegree of a vertex is 0 then pushing it to queue
	    for(int i=0;i<V;i++)
        {
            if(indegree[i]==0){
                nodes.push(i);
                visited[i] = 1;
            }
        }
        //All nodes whose indegree 0 are already pushed into the queue 
        //so all components will be traversed, so just do BFS on queue
        
        return bfsTopoSort(adj, visited, nodes, indegree);
	}
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
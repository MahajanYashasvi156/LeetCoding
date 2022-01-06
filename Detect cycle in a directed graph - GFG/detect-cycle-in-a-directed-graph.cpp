// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    /*
    Approach 2 - Using Topological sort(Modified BFS) with Indegree 0. 
    TC - O(V+E) //For finding indegree also we require V+E + BFS Traversal.
    SC - O(V)   //queue,visited,indegree.
    
    */
    void TopoIndegree(vector<int> adj[],vector<bool> &visited,queue<int>&q,vector<int>&indegree)
	{
    	  while(!q.empty())
    	  {
    	     int source = q.front();
    	     q.pop();
    	     
            //Performing BFS traversal with a modification, 
            //while traversing adjacent nodes, decrementing their indegrees(as if we removing the edge)
            //if indegree became 0, then marking it visited and pushing it to our queue
            //So modified BFS where node is called visited when the node have 0 indegree 
    	     
    	     for(int dest:adj[source])
    	     {
    	         indegree[dest]--;
    	         if(indegree[dest]==0)
    	           {
    	              visited[dest]=true;
    	              q.push(dest); 
    	           } 
    	     }
    	  }
	}
  public:
   
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
       queue<int> q;
	   vector<bool> visited(V+1);
	   vector<int>indegree(V+1,0);
	   
	   //Find Indegree of all the nodes. 
	   //Indegree of nodes is the number of incoming edges.
	   for(int start=0;start<V;start++)
	   {
	       for(int end:adj[start])
	       {
	           indegree[end]++;
	       }
	   }
	   
	   //Push all the nodes to the queue whose indegree is zero.
	   for(int i=0;i<V;i++)
	   {
	       if(indegree[i]==0)
           {
               visited[i]=true;
               q.push(i); 
           } 
	   }
	   
	   //All nodes whose indegree 0 are already pushes into the queue so all components will be traversed.
	    TopoIndegree(adj,visited,q,indegree);
	    
	    //After Topological Sort if any of the node is not visited.
	    //That means its indegree not became 0 and were not added into the queue thus graph has cycle.
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	            return true;
	    }
       return false;
    }
};
/*
Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/#

TC - O(V + E)
Aux SC - O(V)
SC - O(2V)

Approach - As it is directed graph, it will be having cycle if we get a node again  on the current DFS traversal

bool checkCycleDFS(int src,vector<int> adj[],vector<bool>&visited,vector<bool>&dfsVisited)
{
   visited[src]=1;
   dfsVisited[src]=1;
   for(int start:adj[src])
   {
       if(visited[start]==false)
       {
            if(checkCycleDFS(start,adj,visited,dfsVisited))
                return true;
       }
       //If start is visited & that too in the current DFS call, then cycle exists
       else if(dfsVisited[start]==true)
            return true;
   }
   //Unvisiting node as we are returning DFS call from that node.
   dfsVisited[src]=0;
   return false;
}

bool isCyclic(int V, vector<int> adj[]) 
{
    vector<bool> visited(V);
    vector<bool> dfsVisited(V);
    
    for(int src=0;src<V;src++)
    {
        if(visited[src]==false)
        {
            //Check cycle for component with src as source vertex.
            if(checkCycleDFS(src,adj,visited,dfsVisited))
                return true;
        }
        
    }
    return false;
}
*/


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
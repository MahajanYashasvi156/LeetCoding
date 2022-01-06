// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    /*
    Link - https://practice.geeksforgeeks.org/problems/topological-sort/1#
    
    TC- O(V+E)
    SC - O(2V)
    ASC - O(V)
    
    
    Appraoch - 
    
    Topo Sort - Only in Directed Acyclic Graph
    Meaning 1 - Nodes which comes first are written first in topo sort(Hen, then egg).
    Meaning 2 - Nodes whose indegree is 0 come first. Then we remove edges from that node to its neighbours, then we pick another node with 0 indegree aas next node in topo sort
    
    Approach - 
    So in our approach, the nodes which appears first in the DFS path should appear first as per topo sort 
    so perform postorder traversal, and store nodes in stack .
    Now popping stack will reverse the order
    
    In short - 
    Just perform DFS. But while leaving a node, just push that node into stack(postorder)
    Then pop stack and we will get topo sort.

    
	public:
	void postOrderdFS(vector<int> adj[],int src,vector<bool> &visited,stack<int>&s)
	{
	    visited[src]=1;
	    for(int dest:adj[src])
	    {
	        if(visited[dest]==false)
	        {
	             postOrderdFS(adj,dest,visited,s);
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
	            postOrderdFS(adj,src,visited,s);
	   }
	   while(!s.empty())
	  {
	      result.push_back(s.top());
	      s.pop();
	  }
	   return result;
	}
	*/
	
	/*
	    Approach 2 - Using BFS with Indegree 0. 
	    TC - O(V+E) //For finding indegree also we require V+E + BFS Traversal.
	    SC - O(V)   //queue,visited,indegree.
	*/
	void bFSIndegree(vector<int> adj[],vector<bool> &visited,queue<int>&q,vector<int>&indegree,vector<int> &result)
	{
    	  while(!q.empty())
    	  {
    	     int source = q.front();
    	     result.push_back(source);
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
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   queue<int> q;
	   vector<int> result;
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
	   bFSIndegree(adj,visited,q,indegree,result);

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
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


/*
    https://codeforces.com/blog/entry/71146?f0a28=1
*/
class Solution 
{
    vector<int> low;
    vector<int> disc;
    vector<int> ap;
  public:
  
    int dfs(int u,int par,vector<int>adj[])
    {
        static int time = 0;
        int children = 0;
        time++;
        low[u] = time;
        disc[u] = time;
        
        
        for(int n : adj[u])
        {
            if(n==par)
                continue;
              
            if(disc[n]==-1)
            {
                children++;
            
                dfs(n,u,adj);
                
                //means there is no edge from descendant to its ancestor so the 
                //current node has to be present to make its ancestor and descendant 
                // a single component.
                if(disc[u]<=low[n])
                {
                    ap[u] = 1;
                }
                else
                {
                    low[u] = min(low[u],low[n]);
                }
            }
            else
            {
                //Backedge
                low[u] = min(low[u],disc[n]);
            }
        }
        return children;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) 
    {
      
        low.resize(V,-1);
        disc.resize(V,-1);
        ap.resize(V,0);
        
       for(int u = 0;u<V;u++)
       {
           if(disc[u]==-1)
           {
               ap[u] = dfs(u,u,adj)>1;
           }
       }
       
       vector<int> result;
       for(int i = 0;i<V;i++)
       {
           if(ap[i])
           {
               result.push_back(i);
           }
       }
       
       if(result.size()==0)
       {
           return {-1};
       }
       return result;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
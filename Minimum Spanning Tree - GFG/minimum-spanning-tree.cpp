// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

/*
Link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

Kruskal Algorithm - 

1. sort the edge list using weight of edge.
2. one by one pick edge from the sorted list add it to the MST if adding that edge wont create cycle.

How to check if they can form cycle? 

Appraoch - Use Disjoint Set Data structure for ensuring that cycle not created.

If the source and destination nodes of that edge has same absolute parent(belong to same component),
then adding that edge will create cycle.
This is because, if the two nodes have same absolute parent that means they have path in between them i.e. they are connected

Disjoint set data structure will maitain the disjoint sets i.e. connected components formed till now

Approach 1 - Union by Find
Here, when adding an edge dont form cycle, we will simply connect there absolute parents and make them
a single set. Using this will keep the disjoint set tree skewed

i.  Without path compression
    Find can take O(V) time as skewed tree can be fored
    TC
    Find - O(V)
    Union - O(V)
    SC 
    O(V)

ii. With path compression
    TC
    Find - O(log V)
    Union - O(log V)
    SC 
    O(V)

Approach 2 - Union by Rank
Here, when adding an edge dont form cycle, we will use rank(sometimes height) to connect there absolute parents and make them
a single set. Using rank will keep the disjoint set tree balanced which help to improve find time complexiy

While adding two sets, add smaller rank set to bigger rank set. 
If same rank, then add anyhow and increase rank of abs parent of merged set

i.  Without path compression
    Find can take O(log V) time as balanced tree is formed
    TC
    Find - O(log V)
    Union - O(log V)
    SC - O(V)

ii. With path compression
    TC
    Find - O(4 * alpha) = O(1)
    Union - O(4 * alpha) = O(1)
    SC - O(V)

*/

/*
Approach 1) i) -  without path compression and union by rank.

TC - O(ElogE+V^2) 
Detailed - ElogE for sorting all edges and  for each edge E(precisely V-1) we have to find use unionSet which takes V times,in total V^2 time.

SC - O(3E +V) = O(E+V)

class Solution
{
    int findPar(vector<int> &parent,int X)
    {
          if(parent[X]==-1)
                return X;
          return findPar(parent,parent[X]);
    }
    
    bool unionSet(vector<int> &parent,int X,int Z)
    {
    	int AbsoluteParentX = findPar(parent,X);
    	int AbsoluteParentZ = findPar(parent,Z);
    	
    	if(AbsoluteParentX!=AbsoluteParentZ)
    	{
    	   parent[AbsoluteParentX]=AbsoluteParentZ;
    	   return true;
    	} 
    	return false;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int>parent(V,-1);
       
       vector<pair<int,pair<int,int>>> edgeList;
       int minSTCost = 0;
       
       for(int start=0; start<V;start++)
       {
           for(auto endList : adj[start])
           {
               int end = endList[0];
               int weight = endList[1];
               edgeList.push_back({weight,{start,end}});
           }
       }
       
       sort(edgeList.begin(),edgeList.end());
       
       int edgeCount = V-1;
       for(auto a : edgeList)
       {
           int weight = a.first;
           int start = a.second.first;
           int end  = a.second.second;
           if(unionSet(parent,start,end))
           {
                minSTCost += weight;
                edgeCount--;
                if(edgeCount==0)
                    return minSTCost;
           }
       }
        
        return minSTCost;
    }
    
};
*/
/*
Approach 2) ii) - Union by Rank with path compression

TC - O(ElogE + V) = O(ElogV)
Detailed - ElogE for sorting all edges and  for each edge E(precisely V-1) we have to find use unionSet which takes O(4*alpha) time i.e. constant,so total V time.

SC - O(3E +2V) = O(E+V)
*/
class Solution
{
    int findPar(vector<int> &parent,int X)
    {
          if(parent[X]==-1)
                return X;
          return parent[X] = findPar(parent,parent[X]);
    }
    
    bool unionSet(vector<int> &parent,vector<int> &rank,int X,int Z)
    {
    	int AbsoluteParentX = findPar(parent,X);
    	int AbsoluteParentZ = findPar(parent,Z);
    	
    	if(AbsoluteParentX!=AbsoluteParentZ)
    	{
    	    if(rank[AbsoluteParentX] < rank[AbsoluteParentZ])
    	        parent[AbsoluteParentX]=AbsoluteParentZ;
    	    else if (rank[AbsoluteParentX] > rank[AbsoluteParentZ])
    	        parent[AbsoluteParentZ]=AbsoluteParentX;
    	    else 
    	    {
    	        parent[AbsoluteParentZ]=AbsoluteParentX;
    	        rank[AbsoluteParentX]++;
    	    }
    	   return true;
    	} 
    	return false;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int>parent(V,-1);
       vector<int>rank(V,0);
       
       vector<pair<int,pair<int,int>>> edgeList;
       int minSTCost = 0;
       
       for(int start=0; start<V;start++)
       {
           for(auto endList : adj[start])
           {
               int end = endList[0];
               int weight = endList[1];
               edgeList.push_back({weight,{start,end}});
           }
       }
       
       sort(edgeList.begin(),edgeList.end());
       
       int edgeCount = V-1;
       for(auto a : edgeList)
       {
           int weight = a.first;
           int start = a.second.first;
           int end  = a.second.second;
           if(unionSet(parent,rank,start,end))
           {
                minSTCost += weight;
                edgeCount--;
                if(edgeCount==0)
                    return minSTCost;
           }
       }
        
        return minSTCost;
    }
    
};



/*
Link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

Approach 1 - Using distance array
TC - O(V^2) 

Detailed expression - V^2 + (V + E) =  O(V^2)
SC - O(V)

adj -> 
source - { {dest,weight}, {dest,weight} }

so if 1 and 2 are adjacent to 0 node then
0 - {1, 12}, {2, 15}



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
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> visited(V,false);
        vector<int> distance(V,INT_MAX);
        
        //Setting first node's distance as 0 to start the algo
        distance[0]=0;
        
        int minSTCost=0;
        
        while(V--)
        {
           //Finding node at minimum distance from visited nodes.
           int source=minWeightNode(distance,visited);
           
           //marking the node visited 
           visited[source]=true;
           //adding the edge wt to that node in total cost
           minSTCost+=distance[source];
           
            //Relaxing the edges to adjacent nodes
            //Relaxing means, if a adjacent node can be reached from current vertex in lesser distance
            //than the already stored distance, then update the distance of adjancent node in distance.
           for(auto dest : adj[source])
           {
               if(visited[dest[0]]==false)
                    distance[dest[0]]=min(distance[dest[0]],dest[1]);
           }
        }
        return minSTCost;
    }
    
};
*/
/*
Approach 2 - Using min heap + distance array

TC - O(E logV) 

Detailed expression - VlogV + (V + E)logV =  O(E logV)
SC - O(V)



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> visited(V,false);
        vector<int> distance(V,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        //Setting first node's distance as 0 to start the algo
        distance[0]=0;
        
        pq.push({0,0});
        int minSTCost=0;
        
        while(V--)
        {
           //Finding node at minimum distance from visited nodes.
           int source=pq.top().second;
           pq.pop();
           
           //marking the node visited 
           visited[source]=true;
           //adding the edge wt to that node in total cost
           minSTCost+=distance[source];
           
            //Relaxing the edges to adjacent nodes
            //Relaxing means, if a adjacent node can be reached from current vertex in lesser distance
            //than the already stored distance, then update the distance of adjancent node in distance.
           for(auto dest : adj[source])
           {
              if(visited[dest[0]]==false and distance[dest[0]]>dest[1])
              {
                  distance[dest[0]]=dest[1];
                  pq.push({dest[1],dest[0]});
              }  
           }
        }
        return minSTCost;
    }
    
};
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
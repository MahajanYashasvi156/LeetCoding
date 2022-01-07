/*
Link - https://leetcode.com/problems/course-schedule/submissions/

This problem boils down to cycle detection in directed graph
We know two approaches for this

1. DFS with localVisited
2. BFS (topo sort wala)

We also have another DFS approach using 3 states rather than 2 

0 if node is unvisited 
1 if it is being processing(its DFS call running)
2 if node is visited(DFS call left that node)

Basically we make a node visited(2) when we leave from that node in DFS call stack.So if in current DFS traversal, if we got node which is in processing state(1), then we say we got cycle. 

This is easier to understand and just slight modification of DFS.

TC - O(V+E)
SC - O(V+E)
ASC - O(V)
*/

class Solution 
{
    bool dfsCanTakeCourse(vector<vector<int>> &adj,vector<int> &status,int src)
    {
        //In processing State.
        status[src]=1;
        
        for(int dest : adj[src])
        {
            //If not viisted then only call further.
            if(status[dest]==0)
            {
                if(dfsCanTakeCourse(adj, status,dest)==false)
                    return false;
            }
            //In directed graph if the processing node comes again this represents cycle.
            else if(status[dest]==1)
                return false;
        }
        
        status[src]=2;
        return true;
    }
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        
        //Status is same as visited.
        vector<int> status(numCourses,0);
        
        //Creating Adjacency List(Directed Graph) from Edge List.
        for(auto edge : prerequisites)
        {
            int start = edge[0];
            int end = edge[1];
            adj[start].push_back(end);
        }
        
        //For all Components.
        for(int src = 0;src< numCourses;src++)
        {
            if(status[src]==0)
            {
                if(dfsCanTakeCourse(adj, status,src)==false)
                    return false;
            }
        }
        return true;
    }
};
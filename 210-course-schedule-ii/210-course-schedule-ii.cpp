/*
Link - https://leetcode.com/problems/course-schedule-ii/

This problem boils down to cycle detection + topo sort in directed graph

We know two approaches for this
1. Topo sort DFS with localVisited for cycle detection check
2. Topo sort DFS with 3 colors/states (0,1,2) for cycle detection check
2. Topo sort BFS with cycle detection check

We are using approach 1 which is combo of our topo sort DFS + localVisited array to detect cycle in directed graph using DFS

TC - O(V+E)
SC - O(V+E)
ASC - O(V)

Approach 1 -

class Solution 
{
    bool topoDFS(int src,int numCourses,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &localvis,stack<int>&s)
    {
        localvis[src]=true;
        visited[src]=true;
        
        for(int dest:adj[src])
        {
            if(visited[dest]==false)
            {
                if(topoDFS(dest,numCourses,adj,visited,localvis,s)==false)
                    return false;
            }
            else if(localvis[dest]==true)
                return false;
            
        }
        s.push(src);
        localvis[src]=false;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        vector<bool> localvis(numCourses,false);
        stack<int>s;
        vector<int> order;
        
        //Directed Graph.
        for(auto edge:prerequisites)
        {
            int start = edge[1];
            int end = edge[0];
            adj[start].push_back(end);
        }
        for(int src=0;src<numCourses;src++)
        {
            if(visited[src]==false)
            {
                if(topoDFS(src,numCourses,adj,visited,localvis,s)==false)
                    return order;
            }  
        }
        
        while(!s.empty())
        {
            order.push_back(s.top());
            s.pop();
        }
        return order;
    }
};
*/

/*
Appraoch 2 - Topo sort DFS with 3 colors/states (0,1,2) for cycle detection check

class Solution 
{
    bool topoDFS(int src,int numCourses,vector<vector<int>> &adj,vector<int> &color,stack<int>&s)
    {
        color[src]=1;
        
        for(int dest:adj[src])
        {
            if(color[dest]==0)
            {
                if(topoDFS(dest,numCourses,adj,color,s)==false)
                    return false;
            }
            else if(color[dest]==1)
                return false;
            
        }
        s.push(src);
        color[src]=2;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> color(numCourses,0);
        stack<int>s;
        vector<int> order;
        
        //Directed Graph.
        for(auto edge:prerequisites)
        {
            int start = edge[1];
            int end = edge[0];
            adj[start].push_back(end);
        }
        for(int src=0;src<numCourses;src++)
        {
            if(color[src]==0)
            {
                if(topoDFS(src,numCourses,adj,color,s)==false)
                    return order;
            }  
        }
        
        while(!s.empty())
        {
            order.push_back(s.top());
            s.pop();
        }
        return order;
    }
};

*/
/*
Appraoch 3 - Topo sort BFS(kahn's algo) + cycle detection.

for cycle detection we can use any algo bt here we have to also provide order in which courses can be opted so topological sort is necessary to applied.

TC - O(V+E)
SC - O(V+E)
*/
class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        queue<int>q;
        vector<int> order;
        vector<int>indegree(numCourses,0);
        
        //Directed Graph.
        for(auto edge:prerequisites)
        {
            int start = edge[1];
            int end = edge[0];
            adj[start].push_back(end);
        }
        
        for(int start=0;start<numCourses;start++)
        {
            for(int end:adj[start])
            {
                indegree[end]++;
            }
        }
        
        for(int course=0;course<numCourses;course++)
        {
            if(indegree[course]==0)
            {
                visited[course]=true;
                q.push(course);
            }      
        }
        while(!q.empty())
        {
            int src =q.front();
            q.pop();
            order.push_back(src);
            for(int dest:adj[src])
            {
                if(visited[dest]==false)
                {
                    indegree[dest]--;
                    if(indegree[dest]==0)
                    {
                        q.push(dest);
                        visited[dest]=true;
                    }
                }
            }
        }
        //After performing BFS topo sort, if all nodes are pushed to the queue once. 
        //this means all nodes has indegree zero once and all nodes are visited 
        //thus there exist a order in which all courses can be taken.
        if(order.size()==numCourses)
            return order;
        //After performing BFS topo sort, if some node are never pushed to the queue. 
        //this means some nodes never has indegree zero thus there will be cycle.
        //thus there not exist any order in which all courses can be taken return empty order.
        else
            return {};
    }
};



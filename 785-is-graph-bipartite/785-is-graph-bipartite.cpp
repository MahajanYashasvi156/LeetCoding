/*
Link - https://leetcode.com/problems/is-graph-bipartite/submissions/

TC - O(V+E)
SC - O(V)
ASC - O(V)

Intuition - If the graph is 2 colorable, then it is bipartite, else it is not bipartite
Approach - 1 DFS

class Solution
{
    
    bool dFS2Colorable(vector<int> &colors,int src,int assignColor, vector<vector<int>>& graph)
    {
        colors[src] = assignColor;
        
        //check if giving this color is safe
        for(int dest:graph[src])
        {
            if(colors[dest]==assignColor)
            {
                return false;
            }
        }
        
        //dFS2Colorable call for unvisited adjacent nodes(if color is -1, then node is unvisited)
        //and passing flipped color to child(e.g. if parent color 0 then pass 1 to child and vice versa)
        for(int dest : graph[src])
        {
            if(colors[dest]==-1)
            {
                if(dFS2Colorable(colors,dest,assignColor^1,graph)==false) //can also use !assignColor
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int vertex = graph.size();
        vector<int> colors(vertex,-1); //default color, also shows node is unvisited
        
        for(int src=0;src<vertex;src++)
        {
            if(colors[src]==-1)     //unvisited node
            {
                //If any component is not bipartite then return false
                if(dFS2Colorable(colors,src,0,graph)==false)
                    return false;
            }
        }
        //Graph is bipartite
        return true;
    }
};
*/

/*
Intuition - If the graph is 2 colorable, then it is bipartite, else it is not bipartite

Approach 2 - BFS

For level 0 node, give 0 color
For level 1 node, give 1 color, and check if it is safe
For level 2 node, give 0 color, and check if it is safe and so on

In nutshell,
Just perform modified BFS with modifications : 
1. Visit the adjacent nodes in traversal by setting a opposite color than parent.
2. While traversing the adjacent nodes to push unvisited nodes in queue, also check if any adjacent node has same color as current source's color, if yes return false as graph is not bipartite


TC - O(V + E)
SC - O(V)
*/
class Solution
{
    bool bfs(int src,vector<vector<int>>& graph, vector<int>& colors, queue<int> &q)
    {
        q.push(src);
        colors[src]=0;
        
        while(!q.empty())
        {    
            int start = q.front();
            q.pop();
            
            for(int dest : graph[start])
            {
                
                if(colors[dest]==-1)//if dest is unvisited
                {
                    //as of now, assign color as it is, while exploring it in next level we will check if its neighbours have same color or not
                    colors[dest]=1-colors[start]; 
                    q.push(dest);
                }
                else if(colors[dest]==colors[start])
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int vertices = graph.size();
        queue<int> q;
        vector<int>colors(vertices,-1);//default color, also showing node is unvisited
        
        for(int src = 0;src<vertices;src++)
        {
            if(colors[src]==-1)
            {
                //If any component is not bipartite then return false
                if(bfs(src,graph,colors,q)==false)
                    return false;
            }
        }
        //graph is bipartite
        return true;
    }
};
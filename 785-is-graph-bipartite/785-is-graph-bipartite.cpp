/*
Link - https://leetcode.com/problems/is-graph-bipartite/submissions/

TC - O(V+E)
SC - O(V)
ASC - O(V)

*/
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
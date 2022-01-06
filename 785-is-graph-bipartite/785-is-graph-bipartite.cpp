class Solution
{
    bool dFS2Colorable(vector<int> &colors,int src,int parentColor, vector<vector<int>>& graph)
    {
        colors[src] = parentColor ^ 1;
        
        for(int dest:graph[src])
        {
            if(colors[dest]==colors[src])
            {
                return false;
            }
        }
        
        for(int dest : graph[src])
        {
            if(colors[dest]==-1)
            {
                if(dFS2Colorable(colors,dest,colors[src],graph)==false)
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int vertex = graph.size();
        vector<int> colors(vertex,-1);
        
        for(int src=0;src<vertex;src++)
        {
            if(colors[src]==-1)
            {
                if(dFS2Colorable(colors,src,0,graph)==false)
                    return false;
            }
        }
        return true;
    }
};
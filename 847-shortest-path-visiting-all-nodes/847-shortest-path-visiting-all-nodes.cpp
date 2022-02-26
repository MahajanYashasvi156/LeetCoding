class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        int endmask = (1<<n)-1;
        queue<pair<int,pair<int,int>>> q;//current node,(Distance,mask)
        set<pair<int,int>> vis; // (current node,mask)
        
        for(int i = 0 ;i<n;i++)
        {
            int mask = 1<<i;
            q.push({i,{0,mask}}); // Base Case, as we have to start with all nodes. The distance of starting from a node is 0. 
            vis.insert({i,mask}); // First node is always visited.
        }
        
        while(!q.empty())
        {
            pair<int,pair<int,int>> temp = q.front();
            q.pop();
            
            int currentNode = temp.first;
            int distance = temp.second.first;
            int mask = temp.second.second;
            
            if(mask == endmask)
                return distance;
            
            for(auto neighbour : graph[currentNode])
            {
                int newMask = mask | 1<<neighbour;
                
                if(vis.find({neighbour,newMask})!=vis.end())//BFS so first appearance will surely have lesser distance.
                    continue;
                else 
                {
                    q.push({neighbour,{distance+1,newMask}});
                    vis.insert({neighbour,newMask});
                }
            }
        }
        
        return 0;
    }
};
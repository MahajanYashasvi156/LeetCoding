/*
Explaination - https://leetcode.com/problems/minimum-height-trees/solution/


*/
class Solution 
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)     
    {
        if(n==1)
            return {0};
        if(n==2)
            return {0,1};
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto e:edges)
        {
            int src = e[0];
            int dst = e[1];
            
            adj[src].push_back(dst);
            adj[dst].push_back(src);
            degree[src]++;
            degree[dst]++;
        }
        
        queue<int> q;
        
        for(int i = 0;i<n;i++)
        {
            if(degree[i]==1)
                q.push(i);
        }
        
        
        //We need to find the node which is at smallest distance from all the leaf nodes. Considering leaf nodes as peripherals of the circle then root nodes with MHT will be centroid of our circle. There can atmost two centroids of our circle(tree). Because for having more than two centroids it must have cycle in it which will cotradict the def of tree.
        vector<int> result;
        while(!q.empty())
        {
            int s = q.size();
            result.clear();
            for(int i = 0;i<s;i++)
            {
                int node = q.front();
                q.pop();
                result.push_back(node);
                for(int n:adj[node])
                {
                    degree[n]--;
                    if(degree[n]==1)
                        q.push(n);
                }
            }
        }
        return result;
    }
};
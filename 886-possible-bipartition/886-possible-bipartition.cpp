class Solution 
{
    bool bfs(int src , vector<vector<int>>& adj,vector<int>& group)
    {
        queue<int> q;
        group[src] = 0;
        q.push(src);
        
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            
            for(int b :adj[a])
            {
                if(group[b]==-1)
                {
                    group[b]= 1-group[a];
                    q.push(b);
                }
                else if(group[b]==group[a])
                    return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        
        vector<int> group(n+1,-1);
        vector<vector<int>> adj(n+1);
        
        for(auto k:dislikes)
        {
            int a = k[0];
            int b = k[1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for(int i = 1 ;i<=n ;i++)
        {
            if(group[i]==-1)
            {
                if(bfs(i,adj,group)==false)
                    return false;
            }
        }
        return true;
    }
};
/*
https://leetcode.com/problems/sum-of-distances-in-tree/discuss/1308366/C%2B%2B-solution-using-dfs-with-explanation-O(N)-time-complexity


*/
class Solution 
{
    void dfs(vector<vector<int>>&adj,int par, int src,vector<int>&ans,vector<int>&count)
    {
        for(int neigbour : adj[src])
        {
            if(neigbour==par) continue;
            dfs(adj,src,neigbour,ans,count);
            
            ans[src]+=(ans[neigbour]+count[neigbour]);
            count[src] += count[neigbour];
        }
        count[src]+=1;
    }
    
    void dfs2(vector<vector<int>>&adj,int par, int src,int n,vector<int>&count,vector<int>&ans)
    {
        for(int neigbour : adj[src])
        {
            if(neigbour==par) continue;
            ans[neigbour] = ans[src]-count[neigbour] + n - count[neigbour];
             dfs2(adj,src,neigbour,n,count,ans);
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(n);
        
        for(auto e:edges)
        {
            int src = e[0];
            int dst = e[1];
            
            adj[src].push_back(dst);
            adj[dst].push_back(src);
        }
        
        vector<int> count(n);
        vector<int>ans(n);
        
        dfs(adj,-1,0,ans,count);
        dfs2(adj,-1,0,n,count,ans);
        
        return ans;
    }
};
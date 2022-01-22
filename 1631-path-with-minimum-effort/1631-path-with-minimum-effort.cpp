/*
class Solution 
{
    bool dfs(int row,int col, int cutoff,vector<vector<int>> &visited,vector<vector<int>>& heights)
    {
        if(row == heights.size()-1 and col == heights[0].size()-1 )
           return true;
         
        bool result = false;
        visited[row][col]=1;
        
        if (visited[row][col]==0 and row>0 and abs(heights[row][col]-heights[row-1][col])<=cutoff)
            result = result or dfs(row-1,col,cutoff,visited,heights);
        
        if (visited[row][col]==0 and row<heights.size()-1 and abs(heights[row][col]-heights[row+1][col])<=cutoff)
            result = result or dfs(row+1,col,cutoff,visited,heights);
        
        if (visited[row][col]==0 and col>0 and abs(heights[row][col]-heights[row][col-1])<=cutoff)
            result = result or dfs(row,col-1,cutoff,visited,heights);
        
        if (visited[row][col]==0 and col<heights[row][col]-1 and abs(heights[row][col]-heights[row][col+1])<=cutoff)
            result = result or dfs(row,col+1,cutoff,visited,heights);
        
       
        return result;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int minElement=INT_MAX;
        int maxElement = INT_MIN;
        
        for(auto a:heights)
        {
            for(int b :a)
            {
                minElement = min(b,minElement);
                maxElement = max(b,maxElement);
            }
        }
        
        int minRange = 0;
        int maxRange = abs(maxElement-minElement);
        int minEff=INT_MAX;
        
        while(minRange<=maxRange)
        {
            int cutoff = (maxRange - minRange)/2;
         
            vector<vector<int>> visited(heights.size(),vector<int>(heights[0].size(),0));
            if(dfs(0,0,cutoff,visited,heights))
            {
                minEff=min(minEff,cutoff);
                maxRange= cutoff-1;
            }
            else
                minRange = cutoff+1;
        }
        return minEff;
    }
};
*/


class Solution {
public:
    bool dfs(vector<vector<int>>& heights,vector<vector<int>>& vis, int u, int v, int ans){
        
        if(u==heights.size()-1 and v==heights[0].size()-1){
            return true;
        }
        
        vis[u][v] = true;
        bool find = false;
        if(u-1>=0 && !vis[u-1][v] && abs(heights[u][v]-heights[u-1][v])<=ans){
            find = find | dfs(heights,vis,u-1,v,ans);
        }
        if(u+1<heights.size() && !vis[u+1][v] && abs(heights[u][v]-heights[u+1][v])<=ans){
            find = find | dfs(heights,vis,u+1,v,ans);
        }
         if(v-1>=0 && !vis[u][v-1] && abs(heights[u][v]-heights[u][v-1])<=ans){
            find = find | dfs(heights,vis,u,v-1,ans);
        }
         if(v+1<heights[0].size() && !vis[u][v+1] && abs(heights[u][v]-heights[u][v+1])<=ans){
            find = find | dfs(heights,vis,u,v+1,ans);
        }
        
        return find;
        
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        
        int l = 0;
        int h = 1000000;
        int ans = INT_MAX;
        while(l<=h){
            
            int mid = (l+h)/2;
            vector<vector<int>>vis(heights.size(),vector<int>(heights[0].size(),0));
            if(dfs(heights,vis,0,0,mid)){
                ans = min(ans,mid);
                h=mid-1;
            } else {
                l = mid+1;
            }
            
            
        }
        return ans;
        
    }
};



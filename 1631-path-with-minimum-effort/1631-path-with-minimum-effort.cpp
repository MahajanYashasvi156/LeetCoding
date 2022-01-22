class Solution 
{
    bool dfs(int row,int col, int prev , int maxDiff,int cutoff,vector<vector<int>> &visited,vector<vector<int>>& heights)
    {
        if(row<0 or row>=heights.size() or col<0 or col>=heights[0].size() or visited[row][col]==1)
            return false;
        
        maxDiff = max(abs(prev-heights[row][col]), maxDiff);
        
        if(maxDiff> cutoff)
            return false;
        
        if(row == heights.size()-1 and col == heights[0].size()-1 )
        {
           if(maxDiff<=cutoff)
                return true;
        } 
        
        prev = heights[row][col];
        visited[row][col]=1;
        
        bool result = dfs(row+1,col,prev,maxDiff,cutoff,visited,heights) or
        dfs(row-1,col,prev,maxDiff,cutoff,visited,heights) or 
        dfs(row,col+1,prev,maxDiff,cutoff,visited,heights) or
        dfs(row,col-1,prev,maxDiff,cutoff,visited,heights);
        
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
        int ans;
        while(minRange<=maxRange)
        {
            int maxDiff = INT_MIN;
            int cutoff = (maxRange + minRange)/2;
            
            vector<vector<int>> visited(heights.size(),vector<int>(heights[0].size(),0));
            if(dfs(0,0,heights[0][0],maxDiff,cutoff,visited,heights))
            {
                ans = cutoff;
                maxRange= cutoff-1;
            }
            else
                minRange = cutoff+1;
        }
        return ans;
    }
};
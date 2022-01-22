class Solution 
{
    bool dfs(int i,int j,int cutoff,vector<vector<int>> &visited,vector<vector<int>>& heights)
    {
        if(i == heights.size()-1 and j == heights[0].size()-1 )
            return true;
        
        visited[i][j]=1;
        
        bool result = false;
        
        if(!result and i+1<heights.size() and visited[i+1][j]==0 and abs(heights[i][j]- heights[i+1][j])<=cutoff)
        {
            result = result or dfs(i+1,j,cutoff,visited,heights);
        }
            
        if(!result and i-1>=0 and visited[i-1][j]==0 and abs(heights[i][j]- heights[i-1][j])<=cutoff)
        {
            result = result or dfs(i-1,j,cutoff,visited,heights);
        } 
        
         if(!result and j+1<heights[0].size() and visited[i][j+1]==0 and abs(heights[i][j]- heights[i][j+1])<=cutoff)
        {
            result = result or dfs(i,j+1,cutoff,visited,heights);
        }   
        
        if(!result and j-1>=0 and visited[i][j-1]==0 and abs(heights[i][j]- heights[i][j-1])<=cutoff)
        {
           result = result or dfs(i,j-1,cutoff,visited,heights); 
        }
        
        
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
            int cutoff = (maxRange + minRange)/2;
            
            vector<vector<int>> visited(heights.size(),vector<int>(heights[0].size(),0));
            if(dfs(0,0,cutoff,visited,heights))
            {
                ans=cutoff;
                maxRange= cutoff-1;
            }
            else
                minRange = cutoff+1;
        }
        return ans;
    }
};
class Solution 
{
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> mat(n+1,vector<int>(n+1));
        vector<int> indegree(n+1,0);
        for(auto edge: edges)
        {
            int start = edge[0];
            int end = edge[1];
            
            mat[start][end]=1;
            mat[end][start]=1;
            
            indegree[end]++;
            indegree[start]++;
        }
        
        
        int minIndegree =INT_MAX;
        for(int i = 1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
               if(mat[i][j])
               {
                   for(int k = j+1;k<=n;k++)
                   {
                       if(mat[j][k] and mat[k][i])
                       {
                           minIndegree=min(minIndegree,indegree[i]+indegree[j]+indegree[k]-6);
                       }
                   }
               }
                
            }
        }
        if (minIndegree ==INT_MAX)
            return -1;
        return minIndegree;
    }
};
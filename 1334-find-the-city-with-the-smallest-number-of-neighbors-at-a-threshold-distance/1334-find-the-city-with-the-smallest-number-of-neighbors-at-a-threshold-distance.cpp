class Solution 
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<long long>>mat(n,vector<long long>(n,INT_MAX));
        for(int i=0;i<n;i++)
            mat[i][i]=0;
        
        for(auto e: edges)
        {
           int start = e[0];
           int end = e[1];
            int weight = e[2];
            
            mat[start][end]=weight;
            mat[end][start]=weight;
        }
        
        for(int k = 0; k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mat[i][j]>(mat[i][k]+mat[k][j]))
                        mat[i][j]=mat[i][k]+mat[k][j];
                }
            }
        }
        int minNeighboursNode=-1;
        int minNeighbours=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count =0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]<=distanceThreshold)
                    count++;
            }
            count--;
            cout<<count;
            cout<<endl;
            if(count<=minNeighbours)
            {
                minNeighbours=count;
                minNeighboursNode=i;
            }
        }
        return minNeighboursNode;
    }
};
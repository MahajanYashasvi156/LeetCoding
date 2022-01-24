class Solution 
{
    int findParent(vector<int> &dsuf,int x)
    {
        if(dsuf[x]==-1)
            return x;
        
        return dsuf[x]=findParent(dsuf,dsuf[x]);
    }
        
    bool unionRank(vector<int> &dsuf,vector<int> &rank,int x,int y)
    {
        int xpar = findParent(dsuf,x);
        int ypar = findParent(dsuf,y);
        
        if(xpar==ypar)
            return true;
        
        if(rank[xpar]>rank[ypar])
            dsuf[ypar]=xpar;
        else if(rank[xpar]<rank[ypar])
            dsuf[xpar]=ypar;
        else
        {
            dsuf[ypar]=xpar;
            rank[xpar]+=1;
        }
        return false;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<int> dsuf(n,-1);
        vector<int> rank(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                     unionRank(dsuf,rank,i,j);
                }
            }
        }
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(dsuf[i]==-1)
                components++;
        }
        return components;
        
    }
};
class Solution 
{
    int findParent(vector<int> &dsuf,int x)
    {
        if(dsuf[x]==-1)
            return x;
        return dsuf[x]=findParent(dsuf,dsuf[x]);
    }
    
    void unionSet(vector<int> &dsuf,vector<int> &rank ,int x,int y)
    {
        int xpar = findParent(dsuf,x);
        int ypar = findParent(dsuf,y);
        
        if(xpar!=ypar)
        {
           if(rank[xpar]>rank[ypar])
           {
                dsuf[ypar]=xpar;
           }
            else if(rank[ypar]>rank[xpar])
           {
                dsuf[xpar]=ypar;
           }
            else
            {
                dsuf[ypar]=xpar;
                rank[xpar]+=1;
            }
        }
    }
    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        vector<int> dsuf_a(n+1,-1);
        vector<int> rank_a(n+1,0);
        
        vector<int> dsuf_b(n+1,-1);
        vector<int> rank_b(n+1,0);
        
       sort(edges.begin(),edges.end());
        
        //Type 3 edges will be at the end.
        //We have to give more prioirty of type 3 so reverse iterate.
        int ans =0;
        int e = edges.size()-1;
        for(int i=e;i>=0; i--)
        {
            int type = edges[i][0];
            int start = edges[i][1];
            int end = edges[i][2];
            if(type==1)
            {
                if(findParent(dsuf_a,start)!=findParent(dsuf_a,end))
                {
                    unionSet(dsuf_a,rank_a,start,end);
                }
                else
                    ans++;
            }
            
            else if(type==2)
            {
                if(findParent(dsuf_b,start)!=findParent(dsuf_b,end))
                {
                    unionSet(dsuf_b,rank_b,start,end);
                }
                else
                    ans++;
            }

            else
            {
                if(findParent(dsuf_a,start)!=findParent(dsuf_a,end))
                {
                    unionSet(dsuf_a,rank_a,start,end);
                    unionSet(dsuf_b,rank_b,start,end);
                }
                else
                    ans++;
            }
            
        } 
        
        int compa=0;
        int compb=0;
        
        for(int i=1;i<=n;i++)
        {
            if(dsuf_a[i]==-1)
                compa++;
            if(dsuf_b[i]==-1)
                compb++;
        }
        if(compa!=1 or compb!=1)
            return -1;
        return ans;
    }
};
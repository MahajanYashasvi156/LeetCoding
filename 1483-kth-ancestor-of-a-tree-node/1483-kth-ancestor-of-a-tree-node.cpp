class TreeAncestor 
{
   
public:
     vector<vector<int>> up{50000,vector<int>(16,-1)};
    vector<vector<int>> child{50000};
    
    void binary_lifting(int src,int par)
    {
        up[src][0] = par;
        
        for(int i = 1;i<16;i++)
        {
            if(up[src][i-1]!=-1)
            {
                up[src][i] = up[up[src][i-1]][i-1];
            }
            else
            {
                up[src][i] = -1;
            }
        }
        
        for(int c : child[src])
        {
            binary_lifting(c,src);
        }
    }
    TreeAncestor(int n, vector<int>& parent) 
    {
        for(int i = 1;i<n;i++)
        {
            child[parent[i]].push_back(i);
        }
        
        binary_lifting(0,-1);
    }
    
    int getKthAncestor(int node, int k) 
    {
        if(node==-1 || k ==0)
            return node;
        for(int i = 16;i>=0;i--)
        {
            if(k & (1<<i))
                return getKthAncestor(up[node][i],k-(1<<i));
        }
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
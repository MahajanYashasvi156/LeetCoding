class Node
{
    public:
    
    Node* links[2];
    int go = 0;
};

class Trie
{
    public:
        Node* root ;
        
        Trie()
        {
            root = new Node();
        }
    
        void insert(int val)
        {
            Node* curr = root;
            for(int i = 31;i>=0;i--)
            {
                int bit = 1 & val>>i;
                
                if(curr->links[bit]==NULL)
                    curr->links[bit] = new Node();
                curr = curr->links[bit];
                curr->go++;
            }
        }
        void remove(int val)
        {
            Node* curr = root;
            for(int i = 31;i>=0;i--)
            {
                int bit = 1 & val>>i;
                curr = curr->links[bit];
                curr->go--;
            }
        }
    
        int findMaxXor(int x)
        {
            int ans = 0;
            
            Node* curr = root;
            for(int i = 31;i>=0;i--)
            {
                int bit = 1 & x>>i;
                
                if(curr->links[1-bit]!=NULL and curr->links[1-bit]->go>0)
                {
                    ans = ans ^ 1<<i;
                    curr = curr->links[1-bit];
                }
                else
                {
                    curr = curr->links[bit];
                }
            }
            return ans;
        }
};


class Solution 
{
    
    void dfs(int root,vector<vector<int>>&graph,vector<vector<int>>& queries,vector<int> &ans,Trie &trie,unordered_map<int,vector<int>>&queryIndex)
    {
        trie.insert(root);
       
        for(int index : queryIndex[root])
        {
            ans[index] = trie.findMaxXor(queries[index][1]);
        }
       
        for(int n : graph[root])
        {
            dfs(n,graph,queries,ans,trie,queryIndex);
        }
        
        trie.remove(root);
        
    }
    public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) 
    {
        int n = parents.size();
        vector<vector<int>> graph(n);
        
        int root = -1;
        
        for(int i = 0;i<n;i++)
        {
            if(parents[i]==-1)
                root = i;
            else
                graph[parents[i]].push_back(i);
        }
        
        unordered_map<int,vector<int>> queryIndex;
        
        for(int i = 0;i<queries.size();i++)
        {
            queryIndex[queries[i][0]].push_back(i);
        }
       
        vector<int> ans(queries.size());
        Trie trie;
        dfs(root,graph,queries,ans,trie,queryIndex);
        
        return ans;
    }
};
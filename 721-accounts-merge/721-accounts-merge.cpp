class Solution 
{
    int findParent(int x, vector<int> &parent)
    {
        if(parent[x] == -1)
            return x;
        return parent[x] = findParent(parent[x],parent);
    }
    
    void unionFind(int x , int y , vector<int>&parent)
    {
        int absoluteParentX = findParent(x,parent);
        int absoluteParentY = findParent(y,parent);
        
        if(absoluteParentX!=absoluteParentY)
        {
            parent[absoluteParentX] = absoluteParentY;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string,int> mailId;
        
        vector<int> parent(accounts.size(),-1); 
        for(int i = 0;i<accounts.size();i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                if(mailId.find(accounts[i][j])!=mailId.end())
                {
                    unionFind(i,mailId[accounts[i][j]],parent);
                }
                else
                {
                     mailId[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int, vector<string>> m;
        
        for(auto a: mailId)
        {
            m[findParent(a.second,parent)].push_back(a.first);
        }
        vector<vector<string>> result;
        
        for(auto &a:m)
        {
            sort(a.second.begin(),a.second.end());
            a.second.insert(a.second.begin(),accounts[a.first][0]);
            result.push_back(a.second);
        }
        return result;
    }
};
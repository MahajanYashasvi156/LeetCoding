class Solution 
{
    void dfs(int num,int n, vector<int>&ans)
    {
        if(num>n)
            return ;
        ans.push_back(num);
        for(int i = 0;i<=9;i++)
             dfs(num*10+i,n,ans);
    }
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for(int i = 1;i<=9;i++)
            dfs(i,n,ans);
        return ans;
    }
};
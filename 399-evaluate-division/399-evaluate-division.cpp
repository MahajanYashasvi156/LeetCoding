class Solution 
{
    bool dfs(map<string, vector<pair<string,double>>> &adj,string num,string den,map<string,bool>& visited, double &ans , double temp)
    {
        visited[num]=true;
        if(num == den)
        {
            ans = temp;
            return true;
        }       
        for(auto dest : adj[num])
        {
            if(visited[dest.first] == false)
            {
                if(dfs(adj,dest.first,den,visited,ans,temp*dest.second)==true)
                    return true;
            }
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations,vector<double>&values,vector<vector<string>>& queries) 
    {
        map<string, vector<pair<string,double>>> adj;
        
        for(int i=0;i< equations.size();i++)
        {
            string start = equations[i][0];
            string end = equations[i][1];
            
            adj[start].push_back({end,values[i]});
            adj[end].push_back({start,1/values[i]});
        }
        vector<double> result;
        for(int i=0;i<queries.size();i++)
        {
            string num = queries[i][0];
            string den = queries[i][1];
            if(adj.find(num)==adj.end() or adj.find(den)==adj.end())
            {
                result.push_back(-1.0);
                continue;
            }
            map<string,bool> visited;
            double ans =-1.0;
            dfs(adj,num,den,visited,ans,1.0);
            result.push_back(ans);
        }    
        return result;
    }
};
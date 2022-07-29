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
        //Assign unique id to each account from 0 to account.size()-1.
        
        //Insert all the email id with their corresponding account no.
        unordered_map<string,int> mailId;
        //Initially all accounts are separate.
        vector<int> parent(accounts.size(),-1); 
        
        for(int i = 0;i<accounts.size();i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                //If the mailId is already a part of some other account then unify that old account and current account.
                if(mailId.find(accounts[i][j])!=mailId.end())
                    unionFind(i,mailId[accounts[i][j]],parent);
                else
                    //just assign curr account no to the mailID.
                     mailId[accounts[i][j]] = i; 
            }
        }
        //This map will handle duplicacy.
        unordered_map<int, vector<string>> m;
        
        //combining all emailid based on their absolute parent.
        for(auto a: mailId)
            m[findParent(a.second,parent)].push_back(a.first);
    
        vector<vector<string>> result;
        for(auto &a:m)
        {
            //sort the email id's
            sort(a.second.begin(),a.second.end());
            //insert the account name in the account detail.
            a.second.insert(a.second.begin(),accounts[a.first][0]);
            //insert account detail
            result.push_back(a.second);
        }
        return result;
    }
};
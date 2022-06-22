class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
       map<int,vector<int>> m;
        vector<int> result;
       for(int i = 0;i<mat.size();i++)
       {
           for(int j = 0;j<mat[0].size();j++)
           {
               m[i+j].push_back(mat[i][j]);
           }
       }
       
        for(auto it : m)
        {
            if(it.first%2==0)
                reverse(it.second.begin(),it.second.end());
            for(int e:it.second)
                result.push_back(e);
        }
        return result;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        set<int> Row ;
    set<int> Col;

    for(int i =0;i<A.size();i++)
    {
        for(int j =0;j<A[i].size();j++)
        {
            if(A[i][j] == 0)
            {
                Row.insert(i);
                Col.insert(j);
            }
        }
    }

    for(int i =0;i<A.size();i++)
    {
        for(int j =0;j<A[i].size();j++)
        {
            if(Row.find(i)!=Row.end() or Col.find(j)!=Col.end())
            {
                A[i][j] = 0;
            }
        }
    }
    }
};
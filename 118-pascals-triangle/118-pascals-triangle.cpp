class Solution {
public:
    vector<vector<int>> generate(int A) 
    {
        vector<vector<int>> result;
        if(A==0)
            return result;

        result.push_back({1});
        vector<int> lastRow;
        lastRow.push_back(1);
        for(int i = 1;i<A;i++)
        {
            for(int j = 1 ;j<lastRow.size();j++)
                 lastRow[j] = result[i-1][j]+result[i-1][j-1];

            lastRow.push_back(1);
            result.push_back(lastRow);
        }
        return result;
    }
};
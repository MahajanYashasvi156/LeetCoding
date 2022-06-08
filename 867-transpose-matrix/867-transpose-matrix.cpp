class Solution 
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> transpose;
        vector<int> actualcolumn;
        for(int j = 0;j<matrix[0].size();j++)
        {
            actualcolumn.clear();
            for(int i = 0;i<matrix.size();i++)
            {
               actualcolumn.push_back(matrix[i][j]);
            }
            transpose.push_back(actualcolumn);
        }
        return transpose;
    }
};
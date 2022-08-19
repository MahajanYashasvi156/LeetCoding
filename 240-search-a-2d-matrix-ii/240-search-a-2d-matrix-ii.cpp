class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = n-1;
        while(i<m and j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
};

/*
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        for(int i = 0;i<matrix.size();i++)
        {
            auto it = lower_bound(matrix[i].begin(),matrix[i].end(),target);
            
            if(it!=matrix[i].end() and *it == target)
                return true;
        }
        return false;
    }
};
*/
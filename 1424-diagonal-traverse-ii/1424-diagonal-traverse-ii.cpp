class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        map<int,vector<int>> diagonal;
    
        for(int i =nums.size()-1;i>=0;i--)
        {
            for(int j =nums[i].size()-1;j>=0;j--)
            {
                diagonal[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> result;
        for(auto it = diagonal.begin();it!=diagonal.end();it++)
        {
            for(auto a:it->second)
            {
                result.push_back(a);
            }
        }
        return result;
    }
};
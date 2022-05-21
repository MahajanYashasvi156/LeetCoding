/*
Sum of row index + column index represents to which diagonal element belongs to.

Maintain map here as we dont know the number of diagonals.

Traverse starting from bottom to top row and left to right columnof the nums matrix m.
*/
class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        map<int,vector<int>> diagonal;
    
        for(int i =nums.size()-1;i>=0;i--)
        {
            for(int j =0;j<nums[i].size();j++)
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
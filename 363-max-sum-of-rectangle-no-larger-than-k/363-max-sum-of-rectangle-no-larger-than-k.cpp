/*
Prerequisites - 
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/

TC - O(N^3)

*/
class Solution 
{
    int kadanes(vector<int>&row,int k)
    {
        set<int> prefixSum;
        int sum = 0;
        int maxi = INT_MIN;
        prefixSum.insert(0);
        for(int i = 0;i<row.size();i++)
        {
            sum = sum + row[i];
        
            auto it = prefixSum.lower_bound(sum-k);
                
            if(it!=prefixSum.end())
                maxi = max(maxi,sum-*it);
        
            prefixSum.insert(sum);
        }
      
        return maxi;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int left = 0;
        int right;
        int maxi = INT_MIN;
        
        for(int left = 0;left<matrix[0].size();left++)
        {
            vector<int>row(matrix.size(),0);
            for(int right = left;right<matrix[0].size();right++)
            {
                for(int i = 0;i<matrix.size();i++)
                    row[i]+=matrix[i][right];
                
                maxi = max(maxi,kadanes(row,k));
            }
        }
        return maxi;
    }
};
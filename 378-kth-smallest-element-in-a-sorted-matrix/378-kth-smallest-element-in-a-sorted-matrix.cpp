class Solution {
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int r = A.size();
    int c = A[0].size();
    int low  = INT_MAX;
    int high = 0;
    //Find minimum and maximum element from the matrix. 
    for(int i = 0 ;i<r;i++)
    {
        low = min(low,A[i][0]);
        high = max(high,A[i][c-1]);
    }
    //Index of the median element 
    int medianIndex = k;
    int candidate = -1;
    while(low<=high) 
    {
        int mid = low+(high-low)/2;
        int count = 0;
        for(int i = 0;i<r;i++)
        {
            //1 5 5 5 9  -> lower bound returns 1 but upper bound return 4. Still there is a chance that 5 is median.
            count += upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(count<medianIndex)
        {
            low = mid+1;
        }
        else 
        {
            //If elements index is greater than or equal to median Index then that may be median index.
            candidate = mid; 
            high = mid-1;
        }
    }
    return candidate;
    }
};
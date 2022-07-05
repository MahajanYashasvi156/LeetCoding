bool comp(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& A) 
    {
        if(A.size()==0)
            return 0;
         sort(A.begin(),A.end(),comp);

        int count = 1;
        int end = A[0][1];
        for(int i = 1;i<A.size();i++)
        {
            if(A[i][0]>=end)
            {
                count++;
                end = A[i][1];
            }
        }
        return A.size()-count;
        
    }
};
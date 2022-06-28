class Solution 
{
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& A) 
    {
        sort(A.begin(),A.end(),comp);

        int count = 0;
        int end = INT_MIN;
        for(int i=0;i<A.size();i++)
        {
            cout<<A[i][0]<<" "<<A[i][1]<<endl;
            if(A[i][0]>end)
            {
                count++;
                end = A[i][1];
            }
        }
        return count;
        
    }
};
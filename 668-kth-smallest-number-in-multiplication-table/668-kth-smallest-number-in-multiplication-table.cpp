class Solution 
{
    //findPos will return the count of numbers which are less than or equal to mid.
    int findLessEqualCount(int mid,int m,int n)
    {
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            ans = ans + min(mid/i,m);
        }
        return ans;
    }
public:
    int findKthNumber(int m, int n, int k) 
    {
        int low = 1;
        int high = m*n;
        
        int mid ;
        int ans = -1;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            int pos = findLessEqualCount(mid,m,n);
            if(pos>=k)
            {
                ans = mid;
                 high = mid-1;
            }
            else 
                low = mid+1;
        }   
        return ans;
    }
};
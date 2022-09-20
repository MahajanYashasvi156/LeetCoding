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
            int count = findLessEqualCount(mid,m,n);
            
            //if this >k it may also possible that mid will be the ans when there are repeatations of mid element. But if ==k then also it may possible that mid doesn't present in our multiplication table. In that case let's say mid is 5 in 2*3 muliplication table and we want 5th smallest value. In this case the count we get is 5 i.e. 1,2,3 and 2,4 . Clearly but the problem is 5 doesn't exist in the table. So we have to check just smaller value than 5 that exist in table.
            
            if(count>=k)
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
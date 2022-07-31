class Solution 
{
    int getGCD(int a,int b)
    {
        if(b==0)
            return a;
        return getGCD(b,a%b);
    }
public:
    int nthMagicalNumber(int n, int a, int b) 
    {
        long long int low = min(a,b);
        long long int high = (long long int)n*min(a,b);
        
        int gcd;
        
        if(a>b)
            gcd = getGCD(a,b);
        else
            gcd = getGCD(b,a);
        
        long long int lcm = a*b/gcd;
        int ans = -1;
        while(low<=high)
        {
            long long int mid = low+(high-low)/2;
       
            long long int count = mid/a + mid/b -mid/lcm;
            if(count<n)
                low = mid+1;
            else
            {
                high = mid-1;
                ans = mid%1000000007;
            }
                
        }
        return ans;
            
    }
};
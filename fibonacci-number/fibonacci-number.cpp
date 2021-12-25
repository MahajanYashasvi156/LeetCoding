//Link - https://leetcode.com/problems/fibonacci-number/submissions/
class Solution 
{
    public:
    /*
    
    Recursive-
    
    Recurrence Relation - T(n)=T(n-1)+T(n-2)
    
    TC- O(2^n)
    SC - O(1)
    ASC- O(n)
    
    int fib(int n)
    {
       if(n==0 or n==1)
           return n ;
        return fib(n-1)+fib(n-2);
    }
    */
    /*
    Memoized DP-

    TC- O(n)
    SC - O(n)
   
    int fibdp(int n , vector<int> &dp)
    {
         if(dp[n]!=0)
             return dp[n];
         if(n==0 or n==1)
            return n ;
         return dp[n]=fibdp(n-1,dp)+fibdp(n-2,dp);
    }
    int fib(int n)
    {
        vector<int> dp(n+1,0);
        return fibdp(n,dp);
    }
     */
    
    /*
    Iterative -
    
    TC- O(n)
    SC - O(1)
    
    int fib(int n)
    {
        int fibn1=1;
        int fibn2=0;
        int fibn;
        if(n==0)
            return fibn2;
        if(n==1)
           return fibn1;
        for(int i=2;i<=n;i++)
        {
            fibn=fibn1+fibn2;
            fibn2=fibn1;
            fibn1=fibn;
        }
        return fibn;
    }
    */
    int fib(int n)
    {
        if(n==0 or n==1)
            return n ;
        
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
    
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
    
        return dp[n];
    }
};
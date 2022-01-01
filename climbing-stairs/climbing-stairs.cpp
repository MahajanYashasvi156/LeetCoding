
// Recurive - TLE 
/*
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        
        int n1 = climbStairs(n-1);
        int n2 = climbStairs(n-2);
        return n1+n2;
    }
};
*/
// Recurive with memoization - TLE 
class Solution 
{
public:
    int  climbStairswithMemoization(int n,vector<int> &qb)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(qb[n]>0)
            return qb[n];
        int n1 = climbStairswithMemoization(n-1,qb);
        int n2 = climbStairswithMemoization(n-2,qb);
        qb[n]=n1+n2;
        return n1+n2;
    }
    int climbStairs(int n) 
    {
        vector<int> qb(n+1,0);
        return climbStairswithMemoization(n,qb);
    }
};


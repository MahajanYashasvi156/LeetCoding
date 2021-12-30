class Solution
{
public:
    long double factnum(int n)
    {
        long double f=1;
        for(int i=n;i>n/2;i--)
            f=f*i;
        return f;
    }
    long double factden(int n)
    {
        long double f=1;
        for(int i=2;i<=n;i++)
            f=f*i;
        return f;
    }
    
    int numTrees(int n) 
    {
        long double num=factnum(2*n);
        long double den=factden(n+1);
        return num/den;
    }
};
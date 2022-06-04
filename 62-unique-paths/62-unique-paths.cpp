/*
//https://www.geeksforgeeks.org/binomial-coefficient-dp-9/

   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1

class Solution 
{
    int binomialCoeff(int n, int k)
    {
        int C[n + 1][k + 1];
        int i, j;

        // Calculate value of Binomial Coefficient
        // in bottom up manner
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= min(i, k); j++) {
                // Base Cases
                if (j == 0 || j == i)
                    C[i][j] = 1;

                // Calculate value using previously
                // stored values
                else
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }

        return C[n][k];
    }
public:
    int uniquePaths(int m, int n) 
    {
        int totalsteps = m+n-2;
        int mini = min(m,n)-1;
        
        return binomialCoeff(totalsteps,mini);
        
    }
};
*/
class Solution 
{
public:
    int uniquePaths(int m, int n)
    {
        double totalsteps = m+n-2;
        double mini = min(m,n)-1;
        
        double ans = 1.0;
        for(int i = 0;i<mini;i++)
        {
            ans = ans* (totalsteps-i)/(i+1);
        }
        return ans;
    }
};
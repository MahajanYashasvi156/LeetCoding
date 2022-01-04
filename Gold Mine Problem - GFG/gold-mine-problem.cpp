// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

/*
Recursive TLE

TC - O(3^(mn))
ASC - O(m)

class Solution
{
public:
    int maxGoldRecursive(int row,int col,int n,int m,vector<vector<int>>M)
    {
        if(row > n-1 or row<0)
            return INT_MIN;
            
        if(col==m-1)
            return M[row][col];
        
        int upRight = maxGoldRecursive(row-1,col+1,n,m,M);
        int right   = maxGoldRecursive(row,col+1,n,m,M);
        int downRight = maxGoldRecursive(row+1,col+1,n,m,M);
        
        return M[row][col]+max(upRight,max(right,downRight));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int result=INT_MIN;
        for(int i=0 ; i< n ;i++)
            result=max(result,maxGoldRecursive(i,0,n,m,M));
        return result;
    }
};
*/
/*
Recursive Memoization 

TC - O(mn)
SC - O(mn)
ASC - O(m) //m is column



class Solution
{
public:
    int maxGoldMemoization(int row,int col,int n,int m,vector<vector<int>>&M,vector<vector<int>>&dp)
    {
        
        if(row > n-1 or row<0)
            return INT_MIN;
            
        if(col==m-1)
            return M[row][col];
            
        if(dp[row][col] !=-1)
            return dp[row][col];
        
        int upRight = maxGoldMemoization(row-1,col+1,n,m,M,dp);
        int right   = maxGoldMemoization(row,col+1,n,m,M,dp);
        int downRight = maxGoldMemoization(row+1,col+1,n,m,M,dp);
        
        dp[row][col] = M[row][col]+max(upRight,max(right,downRight));
        return dp[row][col];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int result=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0 ; i< n ;i++)
        {
            result=max(result,maxGoldMemoization(i,0,n,m,M,dp));
        }
        return result;
    }
};
*/
/*
Iterative DP - Approach 1 

Iterate from last column to first column.

TC - O(mn)
SC - O(mn)
ASC - O(1)
*/

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int gold=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int col=m-1 ; col>=0 ; col--)
        {
            for(int row=0 ; row<n;row++)
            {
                if(col==m-1)
                {
                    dp[row][col]=M[row][col];
                    continue;
                }
                    
        
                int upRight = INT_MIN;
                int right   = INT_MIN;
                int downRight =INT_MIN;
                
                if(row>0)
                    upRight = dp[row-1][col+1];
                    
                right = dp[row][col+1];
                
                if(row<n-1)
                    downRight = dp[row+1][col+1];
                
                dp[row][col] = M[row][col]+max(upRight,max(right,downRight));
            }
        }
        for(int row=0;row<n;row++)
            gold=max(gold,dp[row][0]);
        
        return gold;
    }
};

/*
Iterative DP - Approach 2

Iterate from last column to first column.

TC - O(mn)
SC - O(mn)
ASC - O(1)

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        if(n==1)
            return accumulate(M[0].begin(),M[0].end(),0);
            
        vector<vector<int>> dp(n,vector<int>(m));
        
        for(int col=m-1 ; col>=0 ; col--)
        {
            for(int row=n-1 ; row>=0;row--)
            {
                if(col==m-1)
                    dp[row][col]=M[row][col];
                    
                else if(row == 0 )
                    dp[row][col] = M[row][col] + max(dp[row][col+1],dp[row+1][col+1]);
                
                else if(row == n-1)  
                    dp[row][col] = M[row][col] + max(dp[row][col+1],dp[row-1][col+1]);
                
                else 
                    dp[row][col] = M[row][col]+max(dp[row][col+1],max(dp[row-1][col+1],dp[row+1][col+1]));
            }
        }
        int gold=INT_MIN;
        for(int row=0;row<n;row++)
            gold=max(gold,dp[row][0]);
        
        return gold;
    }
};
*/

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
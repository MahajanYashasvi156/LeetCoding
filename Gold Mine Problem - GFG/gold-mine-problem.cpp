// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

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
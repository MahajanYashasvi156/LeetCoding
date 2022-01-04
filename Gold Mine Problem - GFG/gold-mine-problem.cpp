// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

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
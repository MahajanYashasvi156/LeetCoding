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
        
        vector<vector<int>> dp(n,vector<int>(m));
        if(n==1)
            return accumulate(M[0].begin(),M[0].end(),0);
            
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
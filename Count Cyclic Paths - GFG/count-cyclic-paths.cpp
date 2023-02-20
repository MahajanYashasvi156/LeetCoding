//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
    int countPaths(int N)
    {
    //   long long dp[4][N+1];
    //   memset(dp,0,sizeof(dp));
    vector<vector<int>> dp(4,vector<int>(N+1,0));
       long M = 1e9+7;
       dp[0][0] = 1;
       for(int i = 1;i<=N;i++)
       {
           long o = dp[0][i-1];
           
           long a = dp[1][i-1];
           
           long b = dp[2][i-1];
           
           long c = dp[3][i-1];
           
           dp[0][i] = (a+b+c)%M;
           dp[1][i] = (o+b+c)%M;
           dp[2][i] = (o+a+c)%M;
           dp[3][i] = (o+a+b)%M;
          
       }
       
       return dp[0][N]%M;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
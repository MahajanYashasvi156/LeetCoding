// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


/*
Link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
TC - O(N^3)
SC - O(N^2)

Matrix Chain Multiplication
Calculate for chain of size 2 - diagonal one above main diagonal
Calculate for chain of size 3 - diagonal two above main diagonal


class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N-1,vector<int>(N-1,INT_MAX));
        
        for(int i=0;i<N-1;i++)
            dp[i][i]=0;

        for(int w=1;w<N;w++)
        {
            for(int i= 0;i < N-1-w ;i++)
            {
                int j=i+w;
            
                for(int k = i;k<j;k++)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1]);
               
            }
        }
       
        return dp[0][N-2];
        
    }
};
*/

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,INT_MAX));
    
        for(int l=1;l<N;l++)
        {
            for(int i = 1;i <=N-l ;i++)
            {
                
                int j=i+l-1;
                if(l==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                for(int k = i;k<j;k++)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
               
            }
        }
       
        return dp[1][N-1];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
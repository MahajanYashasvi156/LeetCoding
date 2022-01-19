// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

/*
class Solution
{
    int recursive(int N, int W,int val[],int wt[],int item)
    {
        if(item==N)
            return 0;
        if(W>=wt[item])
        {
            int pick=recursive(N,W-wt[item],val,wt,item)+val[item];
            int notPick = recursive(N,W,val,wt,item+1);
            return max(pick,notPick);
        }
        return recursive(N,W,val,wt,item+1);
    }
public:
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        
        return recursive(N,W,val,wt,0);
    }
};
*/
class Solution
{
    
    int memoization(int N, int W,int val[],int wt[],int item,vector<vector<int>>&dp)
    {
        if(item==N)
            return 0;
        if(dp[item][W]!=-1)
            return dp[item][W];
        if(W>=wt[item])
        {
            int pick=memoization(N,W-wt[item],val,wt,item,dp)+val[item];
            int notPick = memoization(N,W,val,wt,item+1,dp);
            return dp[item][W]=max(pick,notPick);
        }
        return dp[item][W]=memoization(N,W,val,wt,item+1,dp);
    }
    
public:
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
      return memoization(N,W,val,wt,0,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    /*
    int recursion(int item,int W, int wt[], int val[], int n) 
    {
         if(item==n)
            return 0;
        
         int pick=0;
         
         if(W>=wt[item])
            pick =  val[item]+recursion(item+1,W-wt[item],wt,val,n);
            
         int notPick =recursion(item+1,W,wt,val,n);
        
        return max(pick,notPick);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        return recursion(0,W,wt,val,n);
    }
    */
    int memoization(int item,int W, int wt[], int val[], int n,vector<vector<int>> &dp) 
    {
         if(item==n)
            return 0;
        
         if(dp[item][W]!=-1)
            return dp[item][W];
            
         int pick=0;
         
         if(W>=wt[item])
            pick =  val[item]+memoization(item+1,W-wt[item],wt,val,n,dp);
            
         int notPick =memoization(item+1,W,wt,val,n,dp);
         
        dp[item][W]=max(pick,notPick);
        return dp[item][W];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return memoization(0,W,wt,val,n,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
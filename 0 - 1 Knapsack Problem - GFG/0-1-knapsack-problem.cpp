// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/*
Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

Recursion TLE - Bottom up approach.

Divide problems such that each subproblem have a sack of smaller weight,
will try to pick and unpick current item and will calculate max profit, 
and return max profit to calling subproblem

TC - O(2^n)
SC - O(1)
ASC - O(n)
*/
/*
class Solution
{
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
  }
};
*/


/*
Recursion + Memoization
TC - O(n*W)
SC - O(n*W)
ASC - O(n)

class Solution
{
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

*/

/*
Tabulation DP
Storage and Meaning 
Why 2D DP ? - Because we don't want repeatation of any item, so we have to distinguish effect of each item, so 2D DP.
Storage and Meaning - dp[item][wt] = will store maximum profit/value obtained with items till item index such that total weight of bag is within wt
Direction - Smaller problem is with no items, how much profit can be achieved, obvio 0
            Bigger problem is with all items, how much profit can be achieved
            
             So for loop from i=0 to total items

Recurrence Formula = 
dp[i][weight] = max(max profit without considering this items and all earlier items, considering this items's values and earlier items's profit with remaining weight);
TC - O(n*W)
SC - O(n*W)
*/
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        
        for(int item=1;item<=n;item++)
        {
            for(int weight=1;weight<=W;weight++)
            {
                if(weight-wt[item-1]>=0)
                    dp[item][weight]=max(dp[item-1][weight],dp[item-1][weight-wt[item-1]]+val[item-1]);
                else
                    dp[item][weight]=dp[item-1][weight];
            }
        }
        
        return dp[n][W];
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
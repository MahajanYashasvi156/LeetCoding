// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int n) 
    {
        vector<long long> dp(n+1);
        dp[0]=1;
        for(int i = 1; i<=n;i++)
        {
            for(int j = 0;j< i;j++)
            {
                dp[i]=(dp[i]+(dp[j]*dp[i-1-j])%1000000007)%1000000007;
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends
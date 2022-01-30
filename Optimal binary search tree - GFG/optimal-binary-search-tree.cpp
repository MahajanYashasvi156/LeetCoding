// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<int> prefix(n,0);
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        prefix[0]=freq[0];
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+freq[i];
            
        for(int l=1;l<=n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int j = i+l-1;
                if(l==1)
                {
                    dp[i][j] = freq[i];
                }
                else
                {
                    int temp;
                    for(int k=i;k<=j;k++)
                    {
                        if(k==i)
                            temp = dp[k+1][j];
                        else if(k==j)
                            temp = dp[i][k-1];
                        else
                            temp = dp[i][k-1]+dp[k+1][j];
                        
                        if(i>0)
                            temp = temp + prefix[j]-prefix[i-1];
                        else
                            temp = temp + prefix[j];
                        
                        dp[i][j]=min(dp[i][j],temp);
                            
                    }
                    
                }
            }
        }
        return dp[0][n-1];
    
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
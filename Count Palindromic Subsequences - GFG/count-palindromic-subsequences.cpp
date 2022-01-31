// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        int n = str.size();
        vector<vector<long long int>> dp(n,vector<long long int>(n,0));
        
        for(int l=1; l<=n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int j = i+l-1;
                
                if(l==1)
                    dp[i][j]=1;
    
                else if(l==2)
                {
                    if(str[i]==str[j])
                        dp[i][j]=3;
                    else
                        dp[i][j]=2;
                }
                else
                {
                    if(str[i]==str[j])
                        dp[i][j]=((dp[i+1][j]+dp[i][j-1])%1000000007+1)%1000000007;
                    else
                        dp[i][j]=((dp[i+1][j]+dp[i][j-1])%1000000007-dp[i+1][j-1])%1000000007;
                }
               dp[i][j]+=1000000007;
               dp[i][j]%=1000000007;
            }
        }
        return dp[0][n-1]%1000000007;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends
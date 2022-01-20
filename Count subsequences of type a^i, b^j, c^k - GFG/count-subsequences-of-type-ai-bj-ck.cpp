// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution
{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) 
    {
        vector<vector<int>> dp(3,vector<int>(s.size()+1,0));
        
        //0th row - a+
        //1st row - a+b+
        //2nd row - a+b+c+
        
        for(int i = 0;i < s.size(); i++)
        {
            if(s[i]=='a')
            {
               dp[0][i+1]=(2*dp[0][i]+1)%1000000007;
               dp[1][i+1]=dp[1][i];
               dp[2][i+1]=dp[2][i];
            }
            else if(s[i]=='b')
            {
                dp[0][i+1]=dp[0][i];
                dp[1][i+1]=((2*dp[1][i])%1000000007+dp[0][i])%1000000007;//in b case 2*(ab)+a
                dp[2][i+1]=dp[2][i];
            }
            else 
            {
               dp[0][i+1]=dp[0][i];
               dp[1][i+1]=dp[1][i];
               dp[2][i+1]=((2*dp[2][i])%1000000007+dp[1][i])%1000000007;//in c case 2*(abc)+ab
            }
        }
        return dp[2][s.size()];
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends
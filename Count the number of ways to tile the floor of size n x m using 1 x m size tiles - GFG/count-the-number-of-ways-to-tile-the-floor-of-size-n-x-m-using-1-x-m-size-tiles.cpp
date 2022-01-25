// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	int countWays(int n, int m)
    {
        vector<int> dp(n+1);
        dp[1]=1;
        dp[0]=1;
        for(int i=2;i<=n;i++)
        {
            if(i<m)
                dp[i]=dp[i-1];
            else
                dp[i]=(dp[i-1]+dp[i-m])%1000000007;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends
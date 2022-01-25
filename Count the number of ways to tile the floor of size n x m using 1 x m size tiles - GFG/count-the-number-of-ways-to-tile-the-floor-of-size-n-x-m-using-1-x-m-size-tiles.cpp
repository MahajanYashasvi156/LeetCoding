// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/*
Link - https://practice.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1/#
TC - O(N)
SC - O(1)
*/
class Solution
{
	public:
	int countWays(int n, int m)
    {
        vector<int> dp(n+1,1);
        dp[0]=0;
        for(int i=m;i<=n;i++)
        {
            if(i==m)
                dp[i]=2;
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
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
    Note :- We want sum of last and first n bits sum equal. So if we are getting sum = 2 from 
    first n bits then we need 2 bits set from that n bits and same we need 2 bits set 
    from last n bits. 
    
    for n = 4

    (4C0)^2 + (4C1)^2 + (4C2)^2 +  ...........(4C4)^2

*/
class Solution
{
	public:
	int mod = 1000000007;
	long long inv(long long int r)
	{
	    if(r==1) return 1;
	    return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
	}
	int compute_value(int n)
	{
	    long long int ans =1, ncr=1;
	    for(int i=1;i<=n;i++)
	    {
	        ncr=(((ncr*(n+1-i))%mod)*inv(i))%mod;
	        ans=(ans+(ncr*ncr)%mod)%mod;
	    }
	    return ans%mod;
	}
};

/*
class Solution{
	public:
	int checkValid(string num)
	{
	    int sum = 0;
	    for(int i = 0;i<num.size()/2;i++)
	    {
	        sum = sum + num[i]-'0';
	    }
	    for(int i = num.size()/2;i<num.size();i++)
	    {
	        sum = sum - num[i]+'0';
	    }
	    return sum==0;
	}
	void solve(string num,int n,int &ans)
	{
	    if(n==0)
	    {
	        ans = ans + checkValid(num);
	        return ;
	    }
	    
	    solve(num+"0",n-1,ans);
	    solve(num+"1",n-1,ans);
	}
	int compute_value(int n)
	{
	    string num = "";
	    int ans = 0;
	    solve(num,2*n,ans);
	    return ans;
	}
};
*/


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    long long countWays(int n, int k)
    {
        if(n==1)
            return k;
        long long lastTwoSame = k;
        long long lastTwoDiff = k*(k-1);
        for(int i=2;i<n;i++)
        {
            long long newlastTwoSame = lastTwoDiff;
            long long newlastTwoDiff = ((lastTwoDiff+lastTwoSame)%1000000007*(k-1))%1000000007;
             
            lastTwoDiff = newlastTwoDiff;
            lastTwoSame = newlastTwoSame;
        }
        
        return (lastTwoDiff+lastTwoSame)%1000000007;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends
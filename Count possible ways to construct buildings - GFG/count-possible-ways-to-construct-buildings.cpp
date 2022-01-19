// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int TotalWays(int N)
	{
	    long long plotsEndingWithBuild=1;
	    long long plotsEndingWithSpace=1;
	    long long prevplotsEndingWithSpace;
	    for(int plot = 2;plot<=N;plot++)
	    {
	        prevplotsEndingWithSpace = plotsEndingWithSpace;
	        plotsEndingWithSpace = (plotsEndingWithSpace+ plotsEndingWithBuild)%1000000007;
	        plotsEndingWithBuild = prevplotsEndingWithSpace;
	    }
	    return ((plotsEndingWithBuild+plotsEndingWithSpace)%1000000007 *((plotsEndingWithBuild+plotsEndingWithSpace)%1000000007))%1000000007 ;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
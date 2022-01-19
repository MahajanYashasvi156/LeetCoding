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

/*
Link - https://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

TC - O(N)
SC - O(1)

Approach - maintain two variables to track no of ways of len-1 where consecutive buildings not allowed ending with building and space
Based on there ending object, update them in each iteration
*/

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
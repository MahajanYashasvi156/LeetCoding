// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
/*
Link - https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1/#

TC - O(N)
SC - O(1)

Approach - maintain two variables to track no of strings of len-1 where consecutive 1's not allowed ending with 0 and 1
Based on there ending digit, update them in each iteration
*/
class Solution
{
public:
	// #define ll long long
	
	ll countStrings(int n) 
	{
	  int stringEnd1=1;//length 1 
	  int stringEnd0=1;//length 1
	  
	  for(int len=2;len<=n;len++)
	  {
	      int prevstringEnd1=stringEnd1;
	      stringEnd1=(stringEnd1+stringEnd0)%(1000000007);
	      stringEnd0=prevstringEnd1;
	  }
	  return (stringEnd1+stringEnd0)%(1000000007);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
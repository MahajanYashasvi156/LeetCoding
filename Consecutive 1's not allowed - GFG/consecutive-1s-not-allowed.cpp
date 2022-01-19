// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution
{
public:
	// #define ll long long
	
	ll countStrings(int n) 
	{
	  int stringEnd1=1;//length 1 
	  int stringEnd0=1;//length 1
	  
	  for(int i=2;i<=n;i++)
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
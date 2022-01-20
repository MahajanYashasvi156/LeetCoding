// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n)
	{
	    int included = 0;
	    int excluded = 0;
	    
	    for(int i=0;i<n;i++)
	    {
	        int newincluded=excluded +arr[i];
	        int newexcluded=max(included,excluded);
	        
	        included = newincluded;
	        excluded = newexcluded;
	    }
	    
	    return max(included,excluded);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
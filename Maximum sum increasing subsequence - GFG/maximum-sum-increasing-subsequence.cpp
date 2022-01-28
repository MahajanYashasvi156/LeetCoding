// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n,0);
	    dp[0]=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        int maxSum = 0;
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                maxSum=max(maxSum,dp[j]);
	            }
	            dp[i]=maxSum+arr[i];
	        }
	    }
	    
	    return *max_element(dp.begin(),dp.end());
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
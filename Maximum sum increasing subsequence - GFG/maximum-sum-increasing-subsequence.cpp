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
	    int result=dp[0];
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
	            if(dp[i]>result)
	                result=dp[i];
	        }
	    }
	    return result;
	    //return *max_element(dp.begin(),dp.end());
	}  
};

/*
Link - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1/
TC - O(N^2)
SC - O(N)

In Long Incr Subsequence, we store size of LIS ending at a a particular index in dp.
Here we will store maxsum of LIS ending at a particular index.
There we tried to maximize on size, here we will maximize sum.
*/

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
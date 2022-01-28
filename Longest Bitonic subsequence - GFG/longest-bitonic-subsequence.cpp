// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> dpINC(n,0);
	    vector<int> dpDec(n,0);
	    
	    dpINC[0]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        int leftMax = 0;
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j])
	            {
	                leftMax=max(dpINC[j],leftMax);
	            }
	        }
	        dpINC[i]= leftMax +1;
	       
	    }
	    
	    dpDec[n-1]=1;
	    for(int i=n-2;i>=0;i--)
	    {
	        
	        int rightMax = 0;
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[i]>nums[j])
	            {
	                rightMax=max(dpDec[j],rightMax);
	            }
	        }
	        dpDec[i]= rightMax +1;
	    }
	    
	    int ans = 0;
	    for(int i = 0 ;i<n;i++)
	    {
	        ans = max(ans , dpINC[i]+dpDec[i]);
	    }
	    return ans-1;
	}
};

/*
Link - https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1/#
TC - O(N^2)
SC - O(N)

In Long Incr Subsequence, we store size of LIS ending at a a particular index in dp.
Here we will use two dps
One to store LIS ending at a particular index
One to store Long Dec Subseq starting at particular index = which is nothing but LIS ending at index if we start looping in reverse order
Now at any index, we have LIS len and LDS len, just add them and -1 and return

Basically, two LIS, return max of sum-1;
*/

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
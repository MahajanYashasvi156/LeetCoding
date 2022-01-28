// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> leftInc(n,0);
	    vector<int> rightInc(n,0);
	    
	    leftInc[0]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        int leftMax = 0;
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j])
	            {
	                leftMax=max(leftInc[j],leftMax);
	            }
	        }
	        leftInc[i]= leftMax +1;
	       
	    }
	    
	    rightInc[n-1]=1;
	    for(int i=n-2;i>=0;i--)
	    {
	        
	        int rightMax = 0;
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[i]>nums[j])
	            {
	                rightMax=max(rightInc[j],rightMax);
	            }
	        }
	        rightInc[i]= rightMax +1;
	    }
	    
	    int ans = 0;
	    for(int i = 0 ;i<n;i++)
	    {
	        ans = max(ans , leftInc[i]+rightInc[i]);
	    }
	    return ans-1;
	}
};

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
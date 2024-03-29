//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution
{
    //similar question - https://leetcode.com/problems/maximum-of-absolute-value-expression/
  public:
    int maxDistance(int arr[], int n) 
    { 
       int min1 = INT_MAX;
       int max1 = INT_MIN;
       int min2 = INT_MAX;
       int max2 = INT_MIN;
       
       for(int i = 0;i<n;i++)
       {
           min1 = min(min1,arr[i]-i);
           max1 = max(max1,arr[i]-i);
           
           
           min2 = min(min2,arr[i]+i);
           max2 = max(max2,arr[i]+i);
           
       }
       
       return max(max1-min1,max2-min2);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends
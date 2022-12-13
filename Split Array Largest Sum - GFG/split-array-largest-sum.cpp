//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
    static int check(int t , int arr[],int K,int N)
    {
        int currSum = 0;
        int count = 1;
        for(int i = 0;i<N;i++)
        {
            if(currSum+arr[i]<=t)
            {
                currSum+=arr[i];
            }
            else
            {
                count++;
                if(arr[i]>t)
                    return false;
                currSum = arr[i];
            }
        }
        
        return count<=K;
    }
  public:
    int splitArray(int arr[] ,int N, int K) 
    {
        int high = 0;
        for(int i = 0;i<N;i++)
        {
            high = high + arr[i];
        }
        
        int low = 0;
        
        int ans = high;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
           // cout<<mid<<" "<<low<<" "<<high<<endl;
            if(check(mid,arr,K,N))
            {
                //cout<<mid<<endl;
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
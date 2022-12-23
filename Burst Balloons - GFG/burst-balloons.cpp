//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    int maxCoins(int n, vector<int> &nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
       n = n + 2;
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        
        for(int l=2;l<=n;l++)
        {
            for(int i = 1 ;i<=n-l;i++)
            {
                int j = i+l-1;
               
                for(int p = i;p<j;p++)
                {
                    dp[i][j]=max(dp[i][j],dp[i][p]+dp[p+1][j]+nums[i-1]*nums[p]*nums[j]);
                }    
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool checkBit(int N, int i)
    {
        return N & (1<<i);
    }
    public:
     long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        vector<vector< long int>>dp(N,vector< long int>(1<<N,0));
        
        for(int i=0;i<N; i++)
        {
            dp[i][1<<i]=1;
        }
        
        vector<vector<int>>adj(N,vector<int>(N,0));
        
        for(auto ele:graph)
        {
            adj[ele[0]-1][ele[1]-1]=1;
            adj[ele[1]-1][ele[0]-1]=1;
        }
        
        for(int mask=1; mask<(1<<N); mask++)
        {
            for(int i=0;i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    if(j!=i and arr[j]!=arr[i] and checkBit(mask,j) and adj[arr[i]-1][arr[j]-1])
                    {
                        dp[i][mask]+=dp[j][mask ^ (1<<i)];
                    }
                }
            }
        }
        
        long long int ans=0;
        
        for(int i=0; i<N; i++)
        {
            ans+=dp[i][(1<<N)-1];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends
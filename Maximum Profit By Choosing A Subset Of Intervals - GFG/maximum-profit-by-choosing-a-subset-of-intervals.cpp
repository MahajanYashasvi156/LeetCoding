//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &J) {
     
        vector<int> dp(n,-1);
    
        sort(J.begin(), J.end());        
        
        function<int(int)> dfs;
        dfs = [&](int i) -> int
        {
            if (i >= n) return 0;
            if (dp[i] >= 0) return dp[i];
            
            vector<int> v = {J[i][1], 0, 0};
            int k = lower_bound(J.begin(), J.end(), v) - J.begin();
            return dp[i] = max(dfs(i+1), J[i][2] + dfs(k));
        };
        
        return dfs(0);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
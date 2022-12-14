//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

/*

    Variation of Kadane's Algorithm.
    
*/
class Solution
{
    public:
        vector<int> findRange(string str, int n) 
        {
            int maxSum = 0;
            int currSumTillNow = 0;
            int l = 0;
            int r = -1;
            int tempL = 0;
            
            vector<int> ans;
            
            for(int i = 0;i<n;i++)
            {
                currSumTillNow = currSumTillNow + (str[i]=='0'? 1 : -1);
                
                if(maxSum<currSumTillNow)
                {
                    l = tempL;
                    r = i;
                    maxSum = currSumTillNow;
                }

                if(currSumTillNow<0)
                {
                    currSumTillNow = 0;
                    tempL = i+1;
                }
            }
            
            if(r==-1)
            {
                ans.push_back(r);
            }
            else
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
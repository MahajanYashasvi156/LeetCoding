//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
  public:
    bool canPair(vector<int> nums, int k) 
    {
        map<int,int> m;
        
        for(int n:nums)
        {
            int mod = n%k;
            
            if(mod==0 and m[mod]>0) 
            {
                m[mod]--;
            }
            else if(mod!=0 and m[k-mod]>0)
            {
                m[k-mod]--;
            }
            else
            {
                m[mod]++;
            }
        }

        for(auto it : m)
        {
            if(it.second > 0)
            {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
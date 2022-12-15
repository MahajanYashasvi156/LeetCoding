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
            
            /*
                4 2
                
                6 14 12 14
                
                for 6 -> mod = 0
                for 14 -> mod = 0
                for 12 -> mod = 0
                for 14 -> mod = 0
                
                if already divisible by 2 then we have to find the pair which is also divisible by 2
                so we need to take modulo.
                
                0 1 2 3 4 5 ______ k-1
                
                for 0 find a pair having mod 0
                
                for 1 find a pair having mod k-1
                
                for 2 find a pair having mod k-2
                
            
            */
            if(m[(k-mod)%k]>0)
            {
                m[(k-mod)%k]--;
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
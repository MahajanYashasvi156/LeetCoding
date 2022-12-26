//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<long long> c;
    public:
        void precompute()
        {
            for(int i = 0;i<64;i++)
            {
                for(int j = i+1;j<64;j++)
                {
                    for(int k = j+1; k<64;k++)
                    {
                        long long  temp = 1L<<i | 1L<<j | 1L<<k;
                        //c.push_back(pow(2,i)+pow(2,j)+pow(2,k));
                        c.push_back(temp);
                    }
                }
            }
            sort(c.begin(),c.end());
        }
        
        long long solve(long long l, long long r)
        {
            int i1 = lower_bound(c.begin(),c.end(),l) - c.begin();
            int i2 = upper_bound(c.begin(),c.end(),r) - c.begin();
            
            return i2-i1;
        }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends
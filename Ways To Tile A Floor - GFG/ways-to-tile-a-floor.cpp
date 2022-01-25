// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long numberOfWays(long long N)
    {
        if(N<3)
            return N;
        int n1=1;
        int n2=2;
        for(int i=3;i<=N;i++)
        {
            int temp=n2;
            n2=(n1+n2)%1000000007;
            n1=temp;
        }
        
        return n2;
    }
};

/*
Link - https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1/#
TC - O(N)
SC - O(1)
Boils down to fibonacci series
*/


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
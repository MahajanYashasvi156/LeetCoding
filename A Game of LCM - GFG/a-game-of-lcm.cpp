//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
  long maxGcd(int N) {
        // code here
        return max(solve(N),solve(N-1));
    }
    long solve(int n){
        long ans=n;
        int added=0;
        for(int i=n-1;i>=1;i--){
            if(gcd(ans,i)==1L){
                ans*=i;
                added++;
            }
            if(added==3)return ans;
        }
        return ans;
    }
    long gcd(long a,long b){
        if(a==0)return b;
        return gcd(b%a,a);
    }
    
    // int solve(int N)
    // {
    //     int ans = N;
    //     int count = 1;
    //     for(int i = N-1;i>=0;i--)
    //     {
    //         if(__gcd(ans,i)==1)
    //         {
    //             ans = ans *i;
    //             count++;
    //         }
    //         if(count==4)
    //             return ans;
    //     }
    //     return ans;
    // }
    // long long maxGcd(int N) 
    // {
    //     max(solve(N),solve(N-1));
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends
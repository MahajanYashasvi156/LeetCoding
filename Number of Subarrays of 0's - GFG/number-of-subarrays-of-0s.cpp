//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
   
   long long ans = 0;
   
   int i = 0;
   int j = 0;
   
   while(j<n)
   {
       if(arr[j]==1)
       {
           i = j+1;
       }
       else
       {
           ans = ans + (j-i+1);
       }
       j = j+1;
   }
   return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends
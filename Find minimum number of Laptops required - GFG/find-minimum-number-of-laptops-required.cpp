//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[])
    {
        vector<vector<int>> A;
        
        for(int i = 0;i<N;i++)
        {
            A.push_back({start[i],end[i]});
        }
        sort(A.begin(),A.end());
    
        priority_queue <int, vector<int>, greater<int> > endTimes;
        
        endTimes.push(A[0][1]);
        
        int Laptops = 1;
      
        for(int i =1;i<A.size();i++)
        {
            if(!endTimes.empty() and endTimes.top()<=A[i][0])
                endTimes.pop();
            endTimes.push(A[i][1]);
            Laptops = max(Laptops,int(endTimes.size()));
        }
        return Laptops;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends
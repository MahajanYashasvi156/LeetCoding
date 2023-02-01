//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
       
       long long prevr = 0;
       long long prevb = 0;
       long long prevg = 0;
       
       for(int i = 0;i<N;i++)
       {
           long long tempr = prevr;
           long long tempb = prevb;
           long long tempg = prevg;
           
           prevr = r[i] + min(tempb,tempg);
           prevg = g[i] + min(tempr,tempb);
           prevb = b[i] + min(tempr,tempg);
       }
       return min(prevr,min(prevg,prevb));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
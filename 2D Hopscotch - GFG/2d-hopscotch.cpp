//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        
        int ans=0;
        if(ty==0) {
            if(isValid(i+1,j,n,m)) ans+=mat[i+1][j];    //down
            if(isValid(i-1,j,n,m)) ans+=mat[i-1][j];    //up
            if(isValid(i,j+1,n,m)) ans+=mat[i][j+1];    //right
            if(isValid(i,j-1,n,m)) ans+=mat[i][j-1];    //left
            if(j%2==0) {
                if(isValid(i-1,j+1,n,m)) ans+=mat[i-1][j+1];    // right-up
                if(isValid(i-1,j-1,n,m)) ans+=mat[i-1][j-1];    // left-up
            } else {
                if(isValid(i+1,j+1,n,m)) ans+=mat[i+1][j+1];    // right-down
                if(isValid(i+1,j-1,n,m)) ans+=mat[i+1][j-1];    // left-down
            }
        } else {
            if(isValid(i+2,j,n,m)) ans+=mat[i+2][j];    // down
            if(isValid(i-2,j,n,m)) ans+=mat[i-2][j];    // up
            if(isValid(i,j+2,n,m)) ans+=mat[i][j+2];    // front
            if(isValid(i,j-2,n,m)) ans+=mat[i][j-2];    // back
            if(j%2==0) {
                if(isValid(i+1,j+1,n,m)) ans+=mat[i+1][j+1];    // right-down
                if(isValid(i-2,j+1,n,m)) ans+=mat[i-2][j+1];    // right-up
                if(isValid(i+1,j-1,n,m)) ans+=mat[i+1][j-1];    // left-down
                if(isValid(i-2,j-1,n,m)) ans+=mat[i-2][j-1];    // left-up

                if(isValid(i+1,j+2,n,m)) ans+=mat[i+1][j+2];    // right-down-right-down
                if(isValid(i+1,j-2,n,m)) ans+=mat[i+1][j-2];    // left-down-left-down
                if(isValid(i-1,j+2,n,m)) ans+=mat[i-1][j+2];    // right-up-right-up
                if(isValid(i-1,j-2,n,m)) ans+=mat[i-1][j-2];    // left-up-left-up
            } else {
                if(isValid(i-1,j+1,n,m)) ans+=mat[i-1][j+1];    // right-up
                if(isValid(i+2,j+1,n,m)) ans+=mat[i+2][j+1];    // right-down
                if(isValid(i-1,j-1,n,m)) ans+=mat[i-1][j-1];    // left-up
                if(isValid(i+2,j-1,n,m)) ans+=mat[i+2][j-1];    // left-down

                if(isValid(i-1,j+2,n,m)) ans+=mat[i-1][j+2];    // right-up-right-up
                if(isValid(i-1,j-2,n,m)) ans+=mat[i-1][j-2];    // left-up-left-up
                if(isValid(i+1,j+2,n,m)) ans+=mat[i+1][j+2];    // right-down-right-down
                if(isValid(i+1,j-2,n,m)) ans+=mat[i+1][j-2];    // left-down-left-down
            }
        }
        return ans;
    }
    static bool isValid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
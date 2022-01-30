// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S)
    {
        vector<vector<int>> dpTrue(N,vector<int>(N,0));
        vector<vector<int>> dpFalse(N,vector<int>(N,0));
        
        for(int l = 1;l<=N;l++)
        {
            for(int i = 0;i<=N-l;i++)
            {
                int j = l+i-1;
                
                if(l==1)
                {
                    if(S[i]=='T')
                        dpTrue[i][j]=1;
                        
                    else if(S[i]=='F')
                        dpFalse[i][j]=1;
                }
                    
                else
                {
                    for(int k=i+1;k<j;k++)
                    {
                        if(S[k]=='&')
                        {
                            dpTrue[i][j] += dpTrue[i][k-1]*dpTrue[k+1][j];
                            dpFalse[i][j] += dpFalse[i][k-1]*dpTrue[k+1][j] + dpTrue[i][k-1]*dpFalse[k+1][j]+dpFalse[i][k-1]*dpFalse[k+1][j];
                        }
                        else if(S[k]=='^')
                        {
                            dpTrue[i][j] += dpFalse[i][k-1]*dpTrue[k+1][j] + dpTrue[i][k-1]*dpFalse[k+1][j];
                            dpFalse[i][j] += dpTrue[i][k-1]*dpTrue[k+1][j]+dpFalse[i][k-1]*dpFalse[k+1][j];
                        }
                        
                        else if(S[k]=='|')
                        {
                            dpTrue[i][j] += dpTrue[i][k-1]*dpTrue[k+1][j]+ dpFalse[i][k-1]*dpTrue[k+1][j] + dpTrue[i][k-1]*dpFalse[k+1][j];
                            dpFalse[i][j] += dpFalse[i][k-1]*dpFalse[k+1][j];
                        }
                       
                    }
                   dpTrue[i][j]=dpTrue[i][j]%1003;
                   dpFalse[i][j]=dpFalse[i][j]%1003;
                }
                
                
            }
            
        }
        return dpTrue[0][N-1]%1003;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
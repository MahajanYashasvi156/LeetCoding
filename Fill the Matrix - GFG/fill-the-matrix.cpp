//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        queue<pair<int,int>> q;
        
        q.push({x-1,y-1});
        int level = 0;
        vector<vector<int>> visited(N,vector<int>(M,0));
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                if(x>0 and visited[x-1][y]==0)
                {
                    q.push({x-1,y});
                    visited[x-1][y] = 1;
                }
                if(x<N-1 and visited[x+1][y]==0)
                {
                    q.push({x+1,y});
                     visited[x+1][y] = 1;
                }
                if(y>0 and visited[x][y-1]==0)
                {
                    q.push({x,y-1});
                     visited[x][y-1] = 1;
                }
                if(y<M-1 and visited[x][y+1]==0)
                {
                    q.push({x,y+1});
                     visited[x][y+1] = 1;
                }
            }
            level++;
        }
        return level-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
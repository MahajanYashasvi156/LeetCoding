//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) 
    {
       vector<int> a;
       
       int i = 0;
       
       while(i<N)
       {
           a.push_back(asteroids[i]);
           while(a.size()>=2)
           {
               int curr = a.back();
               a.pop_back();
               int last = a.back();
               a.pop_back();
               
               if(curr<0 and last>0)
               {
                   if(abs(curr)!=abs(last))
                   {
                       if(abs(curr)>abs(last))
                       {
                           a.push_back(curr);
                       }
                       else
                       {
                           a.push_back(last);
                       }
                   }
               }
               else
               {
                   a.push_back(last);
                    a.push_back(curr);
                    
                    break;
               }
           }
           i++;
       }
       return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution 
{
  public:
    string BalancedString(int N) 
    {
         string result;
         string allChar = "abcdefghijklmnopqrstuvwxyz";
         
         int countOfAllChar = N/26;
         for(int i = 0;i<countOfAllChar;i++)
         {
             result.append(allChar);
         }
         
         int r = N%26;
         
        //If N is even 
        if(r%2==0)
        {
            int k = r/2;
            for(int i = 0;i<k;i++)
            {
                result+= ((char)'a'+i);
            }
            for(int i = 26-k;i<26;i++)
            {
                result+= ((char)'a'+i);
            }
        }
        else
        {
            int sum = 0;
            int tempN = N;
            
            while(tempN>0)
            {
                sum = sum + tempN%10;
                tempN = tempN/10;
            }
            
            int start;
            int end;
            
            if(sum%2==0)
            {
                start = (r+1)/2;
                end = (r-1)/2;
            }
            else
            {
                start = (r-1)/2;
                end = (r+1)/2;
            }
            
            for(int i = 0;i<start;i++)
            {
               result+= ((char)'a'+i);
            }
            
            for(int i = 26-end;i<26;i++)
            {
                result+= ((char)'a'+i);
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
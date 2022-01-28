// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++

/*
Link - https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
TC - O(N)
SC - O(1)

Catalan No CN(N) = (2N)C(N) / (N+1) = (2N)! / N! (N+1)!

class Solution
{
    public:
    cpp_int findCatalan(int n) 
    {
        vector<cpp_int> dp(2*n+1);
        dp[0]=1;
        for(int i=1;i<=2*n;i++)
        {
            dp[i]=dp[i-1]*i;
        }
        
        return dp[2*n]/(dp[n]*dp[n+1]);
    }
};
*/

class Solution
{
    public:
    cpp_int findCatalan(int n) 
    {
        vector<cpp_int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            cpp_int catalani=0;
            for(int j=0;j<i;j++)
            {
                catalani+=dp[j]*dp[i-j-1];
            }
            dp[i]=catalani;
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends
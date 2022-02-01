/*
Link - https://leetcode.com/problems/palindromic-substrings/

Brute Force - Generate all n*(n+1)/2 substrings and check if it is palindrome or not.That will take O(N^3) time.

Optimized - DP GAP strategy.
TC - O(N^2)
SC - O(N^2)
*/

class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int palSubStrings = 0;
        for(int l =1;l<=n;l++)
        {
            for(int i = 0;i<=n-l;i++)
            {
                int j = i+l-1;
                if(l==1)
                    dp[i][j]=true;
                else if(l==2)
                    dp[i][j]=s[i]==s[j];   
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1])
                        dp[i][j]=true;
            
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j])
                    palSubStrings++;
            }
        } 
        return palSubStrings;
    }
};
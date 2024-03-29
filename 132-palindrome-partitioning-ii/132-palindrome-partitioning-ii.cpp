/*
    Example of 1 D DP MCM
    
    Bottom Up DP.
    
    Start Solving from n-1 to n-1. 
    
    i is the start of subproblem substring and j is end of the subproblem substring.
    
    
*/

class Solution 
{
    bool isPalindrome(string &s,int l,int h)
    {
        while(l<h)
        {
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
public:
    int minCut(string s) 
    {
        int n = s.size();
        vector<int> dp(n,0);
        
        int j = n-1;
        
        for(int i = n-1;i>=0;i--)
        {
            int ans = INT_MAX;
            for(int k = j;k>=i;k--)
            {
                if(isPalindrome(s,i,k))
                {
                    if(k<j)
                        ans = min(ans,1+dp[k+1]);
                    else
                        ans = 0;
                }
            }

            dp[i] = ans;
        }
        return dp[0];
    }
};


/*
class Solution 
{
    bool isPalindrome(string &s,int l,int h)
    {
        while(l<h)
        {
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
    int MCM(string &s,vector<int> &dp,int i)
    {
        int j = s.size()-1;
        
        if(i>=j)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans = INT_MAX;
        
        for(int k = i;k<=j;k++)
        {
            if(isPalindrome(s,i,k))
            {
                if(k==j)
                    ans = min(ans,MCM(s,dp,k+1));
                else
                    ans = min(ans, 1 + MCM(s,dp,k+1));
            }
        }
        
        return dp[i]=ans;
    }
public:
    int minCut(string s) 
    {
        int n = s.size();
        vector<int> dp(n,-1);
        return MCM(s,dp,0);
    }
};



/*
Link - https://leetcode.com/problems/palindrome-partitioning-ii/

Gap strategy variation

TC - O(N^2)
SC - O(N^2)
*/
/*

class Solution {
public:
    int minCut(string s) 
    {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        
        for(int l = 1;l<=n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int j = l+i-1;
                
                if(l==1)
                    isPalindrome[i][j]=true;
                
                else if(l==2)
                        isPalindrome[i][j]=s[i]==s[j];
                
                else
                {
                    if(s[i]==s[j] and isPalindrome[i+1][j-1])
                        isPalindrome[i][j]=true;
                    else
                        isPalindrome[i][j]=false;
                }
            }
        }
        vector<int> suffixPalindrome(n,INT_MAX);
        suffixPalindrome[0]=0;
        for(int i=1;i<n;i++)//end of suffix
        {
            for(int j=i;j>=0;j--)//start of suffix
            {
                if(isPalindrome[j][i])
                {
                    if(j==0)
                        suffixPalindrome[i]=0;
                   else
                        suffixPalindrome[i]=min(suffixPalindrome[i],suffixPalindrome[j-1]+1);
                }
            }
        }
        return suffixPalindrome[n-1];
    }
};
*/
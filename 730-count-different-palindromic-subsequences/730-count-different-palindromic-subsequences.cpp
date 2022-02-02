/*
Link - https://leetcode.com/problems/count-different-palindromic-subsequences/submissions/

TC - O(N^2)
SC - O(N^2)
*/
class Solution 
{
public:
    int countPalindromicSubsequences(string s) 
    {
        int n = s.size();
        vector<vector<long long>> dp(n,vector<long long>(n));
        
        vector<pair<int,int>> prenext(n,pair<int,int>({-1,-1}));
        
        int lasta=-1;
        int lastb=-1;
        int lastc=-1;
        int lastd=-1;
        
        for(int i=0;i<n;i++)
        { 
            if(s[i]=='a')
            {
                prenext[i].first=lasta;
                if(lasta!=-1)
                    prenext[lasta].second= i;
                lasta=i;
            }
            else if(s[i]=='b')
            {
                prenext[i].first=lastb;
                if(lastb!=-1)
                    prenext[lastb].second= i;
                lastb=i;
            }
            else if(s[i]=='c')
            {
                prenext[i].first=lastc;
                if(lastc!=-1)
                    prenext[lastc].second= i;
                lastc=i;
            }
            else if(s[i]=='d')
            {
                prenext[i].first=lastd;
                if(lastd!=-1)
                    prenext[lastd].second= i;
                lastd=i;
            }
        }
        
        for(int l = 1; l<= n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int j = i+l-1;
                
                if(l==1 or l ==2)
                    dp[i][j]= l;
                else
                {
                    if(s[i]!=s[j])
                        dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                    
                    else
                    {
                        int count = 0;
                        int k =prenext[i].second;
                        while(k!=j)
                        {
                            k = prenext[k].second;
                            count++;
                        }
                        if(count ==0)
                        {
                            dp[i][j]=2*dp[i+1][j-1]+2;
                        }
                        else if (count ==1)
                        {
                             dp[i][j]=2*dp[i+1][j-1]+1;
                        }
                        else 
                        {
                            int next = prenext[i].second;
                            int prev = prenext[j].first;
                             dp[i][j]=2*dp[i+1][j-1]-dp[next+1][prev-1];
                        }
                    }
                    dp[i][j]=dp[i][j]+1000000007;
                    dp[i][j]=dp[i][j]%1000000007;
                }
            }
        }
        return dp[0][n-1];
    }
};
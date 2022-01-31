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
        for(int i=1;i<n;i++)
        {
            for(int j=i;j>=0;j--)
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
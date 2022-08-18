class Solution 
{
public:
    int longestIdealString(string s, int k) 
    {
        vector<int> albhapets(26,0);
        
        int longest = INT_MIN;
        for(int i = 0;i<s.size();i++)
        {
            int c = s[i] - 'a';
            int ans = 1;
            for(int j = max(c-k,0) ;j<min(c+k+1,26);j++)
            {
                ans = max(ans,albhapets[j]+1);
            }
            albhapets[c] = max(albhapets[c],ans);
            longest = max(longest,ans);
        }
        return longest;
        
    }
};
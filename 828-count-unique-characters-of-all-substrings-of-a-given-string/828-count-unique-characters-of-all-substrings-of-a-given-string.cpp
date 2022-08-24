class Solution 
{
public:
    int uniqueLetterString(string s) 
    {
        int p = 0;
        int ans = 0;
        
        vector<int> first(26,-1);
        vector<int> second(26,-1);
        int q , r;
        for(int i = 0;i<s.size();i++)
        {
            int c = s[i] - 'A';
            //q is the no of substring having no occurence of s[i].
            int j = first[c];
            int k = second[c];
            
            q = i-j-1;
            //r is the no of substring having exactly one occurence of s[i]
            r = j - k;
            
            p = p + q-r+ 1;
            ans = ans + p;
           
            second[c] = first[c];
            first[c] = i;
        }
        return ans;
    }
};
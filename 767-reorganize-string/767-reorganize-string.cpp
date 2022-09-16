class Solution {
public:
    string reorganizeString(string s) 
    {
        vector<int> freq(26,0);
        
        for(int i = 0;i<s.size();i++)
            freq[s[i]-'a']++;

        int prev = -1;
        string ans = "";
        for(int i = 0;i<s.size();i++)
        {
            int maxFreq = 0;
            char curr = '$';
            
            for(int j = 0;j<26;j++)
            {
                if(freq[j]>maxFreq and j!=prev)
                    maxFreq = freq[j] , curr = j + 'a';
            }
            
            if(maxFreq==0)
                return "";
            ans = ans + curr;
            freq[curr-'a']--;
            prev = curr-'a';
        }
        return ans;
    }
};
class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char,int> pfreq;
        map<char,int> sfreq;
        vector<int> result;
        for(int i=0;i<p.size();i++)
            pfreq[p[i]]++;
        
        int w = p.size();
        for(int i=0;i<s.size();i++)
        {
            sfreq[s[i]]++;
            if(i>=w-1)
            {
                if(pfreq==sfreq)
                    result.push_back(i-w+1);
                sfreq[s[i-w+1]]--;
                if(sfreq[s[i-w+1]]==0)
                    sfreq.erase(s[i-w+1]);
            }
        }
        
        return result;
    }
};
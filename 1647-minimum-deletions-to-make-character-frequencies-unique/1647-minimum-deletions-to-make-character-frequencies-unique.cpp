class Solution 
{
    
public:
    int minDeletions(string s) 
    {
        int deletions = 0;
        sort(s.begin(),s.end());
        unordered_map<int,char> freq;
        for(int i = 0;i<s.size();i++)
        {
            int currfreq = 1;
            while(s[i]==s[i+1])
            {
                i++;
                currfreq++;
            }
            int currDeletions = 0;
            while(currfreq>0 and freq.find(currfreq)!=freq.end())
            {
                currfreq--;
                currDeletions++;
            }
            freq[currfreq] = s[i];
            deletions = deletions+currDeletions;
            
        }
        return deletions;
    }
};
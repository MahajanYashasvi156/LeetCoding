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
            int curr = 1;
            while(s[i]==s[i+1])
            {
                i++;
                curr++;
            }
            int currDeletions = 0;
            while(curr>0 and freq.find(curr)!=freq.end())
            {
                curr--;
                currDeletions++;
            }
            //cout<<currDeletions<<" "<<s[i]<<" "<<curr<<endl;
            freq[curr] = s[i];
            deletions = deletions+currDeletions;
            
        }
        return deletions;
    }
};
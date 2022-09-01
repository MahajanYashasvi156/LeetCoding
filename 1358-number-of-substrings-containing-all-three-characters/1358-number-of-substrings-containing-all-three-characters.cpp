class Solution 
{
public:
    int numberOfSubstrings(string s) 
    {
        unordered_map<char,int> m;
        
        int low = 0;
        int high = 0;
        int ans = 0;
        
        while(high<s.size())
        {
            m[s[high]]++;
            

            while(m.size()==3)
            {
                m[s[low]]--;
                if(m[s[low]]==0)
                    m.erase(s[low]);
                ans = ans + s.size()-high;
                low++;

            }
            high++;
        }
        return ans;
    }
};
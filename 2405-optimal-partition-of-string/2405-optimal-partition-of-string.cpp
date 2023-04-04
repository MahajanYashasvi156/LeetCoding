class Solution {
public:
    int partitionString(string s) 
    {
        unordered_map<char,int> m;
        
        int ans = 1;
        
        int i = 0;
        
        while(i<s.size())
        {
            if(m[s[i]]!=0)
            {
                ans++;
                m.clear();
            }
            
            m[s[i]]++;
            i++;
            
        }
        return ans;
        
    }
};
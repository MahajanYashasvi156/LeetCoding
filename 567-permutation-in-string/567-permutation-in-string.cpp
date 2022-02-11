class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        map<char,int> s1map;
        map<char,int> s2map;
        
        for(int i=0;i<s1.size();i++)
            s1map[s1[i]]++;
        
        int ws = s1.size();
        for(int i=0;i<s2.size();i++)
        {
            s2map[s2[i]]++;
            if(i>=ws-1)
            {
                if(s1map==s2map)
                    return true;
                else
                {
                    s2map[s2[i-ws+1]]--;
                    if(s2map[s2[i-ws+1]]==0)
                        s2map.erase(s2[i-ws+1]);
                }
            }
        }
        return false;
    }
};
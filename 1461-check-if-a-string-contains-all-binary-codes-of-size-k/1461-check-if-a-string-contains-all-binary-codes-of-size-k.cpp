class Solution 
{
public:
    bool hasAllCodes(string s, int k) 
    {
        unordered_map<string,int> m;
        
        string curr = "";
        
        for(int i = 0;i<s.size();i++)
        {
            curr = curr + s[i];
            
            if(i>=k-1)
            {
                m[curr] =1;
                curr.erase(curr.begin());
            }
        }
        if(m.size()==pow(2,k))
            return true;
        return false;
    }
};
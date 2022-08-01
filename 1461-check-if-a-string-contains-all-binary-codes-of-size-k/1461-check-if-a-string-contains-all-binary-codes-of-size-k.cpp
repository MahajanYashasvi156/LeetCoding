/*
We need only to check all sub-strings of length k.

we can treat the string as a binary number, and take its decimal form as the hash value. In this case, each binary number has a unique hash value.
 
Efficiently Rolling hash  
*/
class Solution 
{
public:
    bool hasAllCodes(string s, int k) 
    {
        unordered_set<int> m;  
        vector<int> roll(k,1);
        
        int p = 1000000007;
        for(int i = k-2;i>=0;i--)
            roll[i] = (roll[i+1]*2)%p;
        
        int hash = 0;
        
        for(int i = 0;i<s.size();i++)
        {
            hash = (hash*2 + s[i]-'0')%p;
            
            if(i>=k-1)
            {
                m.insert(hash);
                hash = ((hash - (s[i-k+1]-'0')*roll[0])%p + p)%p;
            }
        }
        if(m.size() == pow(2,k))
            return true;
        return false;
        
    }
};

/*

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
*/
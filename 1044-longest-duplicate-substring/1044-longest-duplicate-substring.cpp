class Solution 
{
    bool search(string &s, string &ans,int &len)
    {
        if(len==0)
            return false;
        vector<long long> roll(len,1);
        
        int p = 10000000007;
        
        for(int i = len-2;i>=0;i--)
        {
            roll[i] = (roll[i+1]*26) %p;
        }
        unordered_map<int,vector<int>> m;
        
        long hashValue = 0;
        for(int i = 0;i<s.size();i++)
        {
           
            hashValue = (hashValue*26%p + s[i]-'a')%p;
           
            if(i>=len-1)
            {
                if(m.find(hashValue)!=m.end())
                {
                    string curr = s.substr(i-len+1,len);
                    for(int j : m[hashValue])
                    {
                        if(s.substr(j,len)==curr)
                        {
                            ans = curr;
                            return true;
                        }
                    }
                }
                m[hashValue].push_back(i-len+1);
                hashValue = ((hashValue - (s[i-len+1]-'a')*roll[0])%p+p)%p;
            }
        }
        return false;
    }
public:
    string longestDupSubstring(string s) 
    {
        int low = 0;
        int high = s.size();
        int len;
        string ans = "";
        
        while(low<=high)
        {
            len = (low+high)>>1;
            
            if(search(s,ans,len))
                low = len+1;

            else
                high = len-1;

        }
        return ans;
    }
};

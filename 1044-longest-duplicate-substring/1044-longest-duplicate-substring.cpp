class Solution 
{
    bool search(string &s, int &start,int &len)
    {
        if(len==0)
            return false;
        vector<long long> multiplier(len,1);
        
        int p = 10000000007;
        
        for(int i = len-2;i>=0;i--)
        {
            multiplier[i] = (multiplier[i+1]*26) %p;
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
                    for(int j : m[hashValue])
                    {
                        if(s.substr(j,len)==s.substr(i-len+1,len))
                        {
                            start = i-len+1;
                            return true;
                        }
                            
                    }
                }
                m[hashValue].push_back(i-len+1);
                hashValue = 
((hashValue - (s[i-len+1]-'a')*multiplier[0])%p + p)%p;
                
               
            }
        }
        return false;
    }
public:
    string longestDupSubstring(string s) 
    {
        int low = 0;
        int high = s.size();
        
        string ans = "";
        int start = -1;
        while(low<=high)
        {
            int len = (low+high)/2;
            
            if(search(s,start,len))
            {
                ans = s.substr(start,len);
                low = len+1;
            }
            else
            {
                high = len-1;
            }
        }
        return ans;
    }
};

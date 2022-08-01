class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if(s.size()<10)
            return {};
        
        unordered_map<long,vector<int>> hashMatch;
        
        vector<long long> hashMultiplier(10);
        hashMultiplier[9] = 1;
        for(int i = 8;i>=0;i--)
        {
            hashMultiplier[i] = (hashMultiplier[i+1]*26)%1000000007;
        }
        
        long long hashValue = 0;
        int i;
        for( i = 0;i<10;i++)
        {
            hashValue = (hashValue*26 + (s[i]-'A'))%1000000007;
            
        }
        hashMatch[hashValue].push_back(i-1);
        cout<<hashValue<<endl;
        set<string> result;
        while(i<s.size())
        {
            hashValue = ((hashValue - ((s[i-10]-'A')*hashMultiplier[0]))%1000000007 + 1000000007)%1000000007;
            hashValue = ((hashValue*26)%1000000007+s[i]-'A')%1000000007;

            if(hashMatch.find(hashValue)!=hashMatch.end())
            {
                string curr = s.substr(i-9,10);
                
                for(int end : hashMatch[hashValue])
                {
                    if(curr==s.substr(end-9,10))
                        result.insert(curr);
                }
            }
            else
            {
                hashMatch[hashValue].push_back(i);
            }
            i++;
        }
        return {result.begin(),result.end()};
    }
};
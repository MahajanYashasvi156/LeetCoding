class Solution 
{
    static bool comp(string &a, string &b)
    {
        return a.size()<b.size();
    }
    bool isPredecessor(string a,string b)
    {
        int i = 0;
        int j = 0;
    
        while(i<a.size() and a[i]==b[j])
            i++,j++;
       
        b.erase(b.begin()+j);
        return a==b;
    }
public:
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),comp);
        vector<int> LWC(words.size(),1);
        int ans = 1;
        for(int i = 1 ;i<words.size();i++)
        {
            for(int j = i-1;j>=0;j--)
            {
              
                if(words[j].size()==words[i].size()-1 and isPredecessor(words[j],words[i]))
                    LWC[i] = max(LWC[i],LWC[j]+1);
            }
          
            ans = max(ans,LWC[i]);
        }
        return ans;
    }
};
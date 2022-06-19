class Solution 
{
public:
    
    string minWindow(string A, string B) 
    {
        unordered_map<char,int> Bmap;
        for(int i = 0;i<B.size();i++)
            Bmap[B[i]]++;

        unordered_map<char,int> m;
        int start = 0;
        string result = "";
        int low = -1;
        int high = -1;
        int i = 0;
        while(i<A.size())
        {
            if(Bmap.find(A[i])!=Bmap.end())
            {
                m[A[i]]++;
            }
            if(Bmap.size()==m.size())
            {
                bool notfound = false;
                for(auto it = Bmap.begin();it!=Bmap.end();it++)
                {
                    char c = it->first;
                    int freq = it->second;
                    if(m[c]<freq)
                    {
                        notfound = true;
                        break;
                    }  
                }
                if(notfound==false)
                {
                    if(high==-1 or (high-low+1)>i-start+1)
                    {
                        low = start;
                        high = i;
                    }
                    if(m.find(A[start])!=m.end())
                    {
                        m[A[start]]--;
                        if(m[A[start]]==0)
                        {
                            m.erase(A[start]);
                        }                 
                    }
                    start++;
                    m[A[i]]--;
                }
                else
                    i++;
            }
            else
                i++;
        }
        if(high==-1)
            return "";
        return A.substr(low,high-low+1);
    }
};
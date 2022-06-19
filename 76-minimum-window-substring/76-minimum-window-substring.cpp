class Solution 
{
public:
    string minWindow(string A, string B) 
    {
        unordered_map<char,int> Bmap;
        for(int i = 0;i<B.size();i++)
            Bmap[B[i]]++;

        unordered_map<char,int> m;
        int start = -1;
        int end = -1;

        int low = 0;
        int high = 0;

        int count = B.size();

        while(high<A.size())
        {
            while(high<A.size() and count>0)
            {  
                m[A[high]]++;
                if(m[A[high]]<=Bmap[A[high]])
                {
                    count--;
                }
                high++;
            }
            //high will point to the next of desired substring.
            while(count==0)
            {
                if(end==-1 or (end-start)>high-low)
                {
                    start = low;
                    end = high;
                }  
                m[A[low]]--;
                if(m[A[low]]<Bmap[A[low]])
                    count++;
                low++;
            }
        }
        if(end==-1)
            return "";
        return A.substr(start,end-start);
    }
};



/*
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
        int low = -1;
        int high = -1;
        int i = 0;
        while(i<A.size())
        {
            m[A[i]]++;
    
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
        if(high==-1)
            return "";
        return A.substr(low,high-low+1);
    }
};
*/
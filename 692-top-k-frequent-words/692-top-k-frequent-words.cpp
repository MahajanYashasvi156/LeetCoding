class myComp
{
    public:
    bool operator()(pair<int,string> a, pair<int,string>b)
    {
        if(a.first>b.first)
            return true;
        if(a.first<b.first)
            return false;
        return a.second<b.second;
    }
};
class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
         priority_queue<pair<int,string>,vector<pair<int,string>>,myComp>  minheap;
        
        unordered_map<string,int> m;
        
        for(string s:words)
            m[s]++;
        
        for(auto a:m)
        {
            string s =a.first;
            int freq = a.second;
           
            if(minheap.size()<k)
            {
                minheap.push({freq,s});
            }
            else
            {
                if(minheap.top().first<freq || (minheap.top().first==freq and minheap.top().second>s))
                {
                    minheap.pop();
                    minheap.push({freq,s});
                }
                
            }
        }
        
        vector<string> result;
        
        while(!minheap.empty())
        {
            result.push_back(minheap.top().second);
            minheap.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
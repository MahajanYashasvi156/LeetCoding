class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        priority_queue<int,vector<int>> maxHeap;
        
        vector<pair<int,int>> cp;
        
        int n = profits.size();
        for(int i = 0;i<n;i++)
        {
            cp.push_back({capital[i],profits[i]});
        }
        
        sort(cp.begin(),cp.end());
        int i = 0;
        
        while(k-->0)
        {
            while(i<n and cp[i].first<=w)
            {
                maxHeap.push(cp[i].second);
                i++;
            }
            
            if(!maxHeap.empty())
            {
                w = w + maxHeap.top();
                maxHeap.pop();
            }
            else
                return w;
            
        }
        return w;
    }
};
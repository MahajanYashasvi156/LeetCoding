class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        for(int i = 0;i<tasks.size();i++)
        {
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(),tasks.end());
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        
        int i = 0;
        
        int last = 0;
        vector<int> ans;
        
        while(i<tasks.size())
        {
            if(last<tasks[i][0] and minHeap.empty()==true)
            {
                last = tasks[i][0];
            } 
            if(minHeap.empty()==false)
            {
                last = last + minHeap.top()[0];
                ans.push_back(minHeap.top()[1]);
                minHeap.pop();
            }
            while(i<tasks.size() and tasks[i][0]<=last)
            {
                 minHeap.push({tasks[i][1],tasks[i][2]});
                i++;
            }
        }
        while(minHeap.empty()==false)
        {
            ans.push_back(minHeap.top()[1]);
            minHeap.pop();
        }
        return ans;
    }
};
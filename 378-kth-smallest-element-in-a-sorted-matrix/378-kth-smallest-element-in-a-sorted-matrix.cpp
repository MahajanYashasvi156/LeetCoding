class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        
        for(int i = 0;i<matrix.size();i++)
        {
            minHeap.push({matrix[i][0],{i,0}});
        }
        
        int count = 0,n,i,j;
        while(count<k)
        {
            n = minHeap.top().first;
            i = minHeap.top().second.first;
            j = minHeap.top().second.second;
            
            count++;
            
            minHeap.pop();
            
            if(j<matrix[i].size()-1)
                minHeap.push({matrix[i][j+1],{i,j+1}});
            
        }
        return n;
    }
};
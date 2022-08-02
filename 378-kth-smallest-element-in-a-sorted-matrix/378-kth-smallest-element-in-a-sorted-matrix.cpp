class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int low = INT_MAX;
        int high = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0;i<m;i++)
        {
            low = min(low,matrix[i][0]);
            high = max(high,matrix[i][n-1]);
        }
        
        int ans ;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int count = 0;
            for(int i = 0;i<m;i++)
            {
                count= count+ lower_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            //1 5 5 5 9  -> lower bound returns 1 but upper bound return 4. Still there is a chance that 5 is median
            if(count<k)
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
               
                high = mid-1;
            }
            
        }
        return ans ;
    }
};


/*
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
*/
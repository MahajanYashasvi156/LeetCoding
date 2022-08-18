class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        long long sum = 0;
        int shortest = INT_MAX;
        deque<pair<long long,int>> dq;//sum,index
        
        for(int i = 0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            
            if(sum>=k)
                shortest = min(shortest,i+1);
            
            pair<long long,int> curr = {INT_MIN,-1};
            
            while(!dq.empty() and (sum-dq.front().first)>=k)
            {
                curr = dq.front();
                dq.pop_front();
            }
            
            if(curr.second!=-1)
            {
                shortest = min(shortest,i-curr.second);
            }
            
            while(!dq.empty() and dq.back().first>=sum)
                dq.pop_back();
            dq.push_back({sum,i});
        }
        return shortest==INT_MAX?-1:shortest;
    }
};
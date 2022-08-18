/*
    Two Pointer Algorithm If not have positive values.
    
    1. left = 0,right = 0;
    2. Increase right till ws>=target. Update shortest= right+1
    3. Now compress the window by increasing left till we get the ws<target.
        update shortest including elements from left-1 to right.shortest=right-left+2
        
    But here because of the presence of negative values we will not get monotonically increasing sum. So for monotonically increasing sum we could think of maintianing stack.
    But we also want to compress window by popping sum from the front so we can maintain queue here.
    
    1. make a pair of queue , sum and index
    2. If the sum >=k then we can find the minimum window size shortest = i+1.
    3. Pop_front elements till we can get sum>=k
       the last element of deque we popped has the start of window. 
       shortest = min(shortest,i-curr.second);
    4. For maintaining montonically sum , we pop elements of deque from last till we get the first value<currsum.
    5. Then we can safely add the curr sum to the deque maintaining the monotonic nature.
*/
class Solution 
{
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
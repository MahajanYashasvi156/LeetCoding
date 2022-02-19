class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        priority_queue<int> pq;
        int min_Ele = INT_MAX;
        for(int a : nums)
        {
            if(a%2)
                a=a*2;
            min_Ele = min(min_Ele, a);
            pq.push(a);
        }
        int diff = INT_MAX;
        int max_Ele = INT_MIN;
        while(pq.size()>1)
        {
            max_Ele = pq.top();
            pq.pop();
            diff = min(diff,max_Ele - min_Ele);
            if(max_Ele%2)
                break;
            pq.push(max_Ele/2);
            min_Ele = min(min_Ele,max_Ele/2);
        }
        return diff;
    }
};
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> s;
        for(int a:nums)
            s.insert(a);
        
        int count = 0;
        int maxSequence = 0;
        int prev = INT_MIN;
        for(int a: s)
        {
            if(prev==INT_MIN || a==prev+1)
            {
                count++;
            }
            else
                count = 1;
            prev = a;
            maxSequence=max(maxSequence,count);
        }
        return maxSequence;
    }
};
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        for(int a:nums)
            m[a]=1;
        int count = 0;
        int maxSequence = 0;
        for(auto v: m)
        {
            int a = v.first;
            if(m.find(a-1)==m.end())
            {
                count = 1;
                while(m.find(++a)!=m.end())
                    count++;
                maxSequence=max(maxSequence,count);
            }
        }
        return maxSequence;
        
    }
};


/*
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
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        
        int maxCount = 0;
        
        for(char c : tasks)
            freq[c]++,maxCount = max(maxCount,freq[c]);
        
        int ans = (maxCount-1)*n + maxCount-1;
        
        for(auto it : freq)
        {
            if(maxCount == it.second)
                ans++;
        }
        return max(ans,(int)tasks.size());
    }
};
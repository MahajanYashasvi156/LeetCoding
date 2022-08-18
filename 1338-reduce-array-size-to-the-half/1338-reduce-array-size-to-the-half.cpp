class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        vector<int> freq;
        unordered_map<int,int> m;
        
        for(int i = 0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        
        for(auto a: m)
        {
            freq.push_back(a.second);
        }
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int n = arr.size();
        int ans=0;
        while(n>arr.size()/2)
        {
            n = n-freq[ans];
            ans++;
        }
        return ans; 
    }
};
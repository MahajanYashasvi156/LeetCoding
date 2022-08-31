class Solution {
public:
    int numSplits(string s)
    {
        unordered_map<char,int> left;
        unordered_map<char,int> right;
        
        left[s[0]] = 1;
        
        for(int i = 1;i<s.size();i++)
        {
            right[s[i]]++;
        }
        
        int ans = 0;
        
        for(int i = 1;i<s.size();i++)
        {
            if(left.size()==right.size())
                ans++;
            
            left[s[i]]++;
            
            right[s[i]]--;
            
            if(right[s[i]]==0)
                right.erase(s[i]);
        }
        return ans;
    }
};
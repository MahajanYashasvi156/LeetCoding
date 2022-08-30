class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> m;
        
        for(int i = 0;i<s.size();i++)
            m[s[i]] = i;
        
        vector<int> result;
        int largest = INT_MIN;
        int length = 0;
        for(int i = 0;i<s.size();i++)
        {
            largest = max(largest,m[s[i]]);
            
            length++;
            if(i==largest)
                result.push_back(length),length=0;
           
        }
        
        return result;
    }
};
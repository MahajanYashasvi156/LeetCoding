class Solution {
public:
    long long appealSum(string s) 
    {
        long long p = 0;
        long long ans = 0;
        
        vector<int> first(26,-1);
   
        long long q , r;
        for(int i = 0;i<s.size();i++)
        {
            int c = s[i] - 'a';
            //q is the no of substring having no occurence of s[i].
            int j = first[c];
          
            q = i-j-1;
            
            p = p + q+ 1;
            ans = ans + p;
           
            first[c] = i;
        }
        return ans;    
    }
};
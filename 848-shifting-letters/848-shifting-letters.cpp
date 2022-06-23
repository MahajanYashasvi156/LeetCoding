class Solution 
{
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        for(int i = shifts.size()-2;i>=0;i--)
        {
            shifts[i]=(shifts[i]+shifts[i+1])%26;
        }
        
        for(int i = 0;i<shifts.size();i++)
        {
            int c = (s[i]-'a'+shifts[i])%26;
            s[i] = c+'a';
        }
        
        return s;
        
    }
};
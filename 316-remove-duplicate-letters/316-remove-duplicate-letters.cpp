/*
Here we are maintaining montonically increasing order of characters with some trick.

For lexicographically smallest string , we can remove the last character if it greater than current character and we can include that last character after the current small character.

TC - O(n)
SC - O(1)
*/
class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        string result = "";
        
        vector<int> count(26,0);
        
        vector<int> used(26,0);
        
        for(int i = 0;i<s.size();i++)
            count[s[i]-'a']++;
        
        for(int i = 0;i<s.size();i++)
        {
            count[s[i]-'a']--;
            
            if(used[s[i]-'a'])
                continue;
            
            used[s[i]-'a']=1;
            
            while(!result.empty() and result.back()>s[i] and count[result.back()-'a']>0)
            {
                used[result.back()-'a']=0;
                result.pop_back();
            }
            
            result.push_back(s[i]);
        }
        return result;
        
    }
};
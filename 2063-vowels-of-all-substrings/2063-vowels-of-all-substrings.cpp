/*

https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

*/
class Solution 
{
public:
    long long countVowels(string word) 
    {
        long long ans = 0;
        
        long long prev = 0;
        
        for(int i = 0;i<word.size();i++)
        {
            
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i] =='o' || word[i]=='u')
            {
                prev = prev + i + 1;
            }
            
            ans = ans + prev;
        }
        return ans;
    }
};
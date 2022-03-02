/*
Link -https://leetcode.com/problems/is-subsequence/submissions/

TC - O(m+n)
SC - O(1)
*/
class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int i = 0;
        int j = 0;
        while(i<s.size() and j<t.size())
        {
            if(s[i]==t[j])
                i++;
            j++;  
        }
        return i==s.size();
    }
};
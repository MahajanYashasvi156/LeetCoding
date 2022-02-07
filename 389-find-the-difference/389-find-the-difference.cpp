/*
Link - https://leetcode.com/problems/find-the-difference/submissions/

TC - O(nlogn)
SC - O(1)


class Solution 
{
  public:
    char findTheDifference(string s, string t) 
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int i=0;
        int j=0;
        while(i<s.size() and j<t.size())
        {
            if(s[i]!=t[j])
            {
                return t[j];
            }
            i++;
            j++;
        }
        return t[j];
    }
};
*/

class Solution 
{
  public:
    char findTheDifference(string s, string t) 
    {    
        int ssum =0;
        int tsum =0;
        for(int i=0;i<s.size();i++)
        {
          ssum +=s[i];  
        }
        for(int i=0;i<t.size();i++)
        {
          tsum +=t[i];  
        }
        return tsum-ssum;
    }
};
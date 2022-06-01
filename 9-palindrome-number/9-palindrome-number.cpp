/*
Link - https://leetcode.com/problems/palindrome-number/

TC - O(log10(n))
SC - O(1)
*/
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        long int reversex = 0;
        int tempx = x;
        while(tempx>0)//to ensure negative numbers also.
        {
            reversex = reversex*10+tempx%10;
            tempx/=10;
        }
        return reversex==x;
        /*
        string s = to_string(x);
        int i=0;
        int j = s.size()-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
        */
    }
};
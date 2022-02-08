/*
Link - https://leetcode.com/problems/add-digits/submissions/

TC - O(1)
SC - O(1)
*/

class Solution 
{
public:
    int addDigits(int num)
    {
        if(num==0)
            return 0;
        if(num%9==0)
            return 9;
        return num%9;
    }
};
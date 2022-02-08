/*
Link - https://leetcode.com/problems/add-digits/submissions/

Algortihm -
If the number is 0 then the sum of that will be 0.
Else if number is exactly divisible by 9 then return 9.
Else return the num%9.

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
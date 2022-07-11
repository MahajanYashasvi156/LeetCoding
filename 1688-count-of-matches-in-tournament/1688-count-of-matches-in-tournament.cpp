/*
class Solution 
{
public:
    int numberOfMatches(int n) 
    {
        return n-1;
    }
};
*/

class Solution 
{
public:
    int numberOfMatches(int n) 
    {
        if(n==1 || n==0)
            return 0;
        if(n%2==0)
            return n/2+numberOfMatches(n/2);
        else
            return n/2+numberOfMatches((n-1)/2+1);
    }
};
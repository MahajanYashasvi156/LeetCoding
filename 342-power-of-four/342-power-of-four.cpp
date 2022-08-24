class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        for(int i = 0;i<32;i=i+2)
        {
            if((n ^ (1<<i)) ==0)
                return true;
        }
        return false;
    }
};

/*

class Solution 
{
public:
    bool isPowerOfFour(int n)
    {
        if(n==0)
            return false;
        int i = 0;
        while(n!=1)
        {
            if(n%4!=0)
                return false;
            n = n/4;
        }
        return true;
    }
};
*/
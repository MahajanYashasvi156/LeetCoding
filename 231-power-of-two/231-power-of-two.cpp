class Solution 
{
public:
    bool isPowerOfTwo(int num) 
    {
        if(num==1)
            return 1;
        if(num%2 or num<1)
            return 0;
        int log2num = log2(num);
        if(pow(2,log2num) == num)
            return 1;
        return 0;
        
    }
};
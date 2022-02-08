class Solution {
public:
    int addDigits(int num)
    {
        if(num==0)
            return 0;
        int modval =num%9;
        
        if(modval==0)
            return 9;
        return modval;
    }
};
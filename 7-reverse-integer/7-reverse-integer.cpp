class Solution {
public:
    int reverse(int A) 
    {
         long int reverseNumber = 0;
        while(A)
        {
            reverseNumber *= 10;
            reverseNumber += A%10;
            A/=10;

        }
        if(reverseNumber>INT_MAX)
            return 0;
        if(reverseNumber<INT_MIN)
            return 0;
        return reverseNumber;    
    }
};
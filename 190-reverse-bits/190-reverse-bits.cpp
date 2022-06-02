class Solution 
{
public:
    uint32_t reverseBits(uint32_t A) 
    {
        /*
        uint32_t reverseA = 0;
        for(int i =0;i<32;i++)
        {
            if(A & 1) 
                reverseA = reverseA + (1<<(31-i));
            A = A>>1;
        }
        return reverseA;
        */
        int low = 0;
        int high = 31;
        while(low<high)
        {
            int x = 0;
            int y = 0;

            if(A & 1<<low)
                x = 1;
            if(A & 1<<high)
                y=1;

            if(x^y)
            {
                A = A ^ (1<<low);
                A = A ^ (1<<high);
            }

            low++;
            high--;
        }
        return A;
    }
};
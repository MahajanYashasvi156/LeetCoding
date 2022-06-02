class Solution 
{
public:
    uint32_t reverseBits(uint32_t A) 
    {
        uint32_t reverseA = 0;
        for(int i =0;i<32;i++)
        {
            if(A & 1) 
                reverseA = reverseA ^ 1<<(31-i);
            A = A>>1;
        }
        return reverseA;
    }
};
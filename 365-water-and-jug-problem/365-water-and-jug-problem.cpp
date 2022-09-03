class Solution 
{
    int findGCD(int a,int b)
    {
        if(b==0)
            return a;
        return findGCD(b,a%b);
    }
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) 
    {
        int gcd = 1;
        
        if(jug1Capacity>jug2Capacity)
            gcd = findGCD(jug1Capacity,jug2Capacity) ; 
        else
            gcd = findGCD(jug2Capacity,jug1Capacity) ; 
        
        return targetCapacity%gcd==0 and targetCapacity<=jug1Capacity+jug2Capacity;
    }
};
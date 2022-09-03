class Solution 
{
    /*
        Approach - Instead of considering two jugs. Consider it as a single jug. 
        
        Total water in both jugs will be operated by +jug1Capacity,-jug1Capacity,+jug2Capacity or -jug2Capacity.
        
        If it possible to have target value by making this operations then we can measure targetCapacity.
        
        
        TC - O(jug1Capacity+jug2Capacity)
    
    */
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        int steps[] = {jug1Capacity,jug2Capacity,-1*jug1Capacity,-1*jug2Capacity};
        
        int totalCapacity = jug1Capacity+jug2Capacity;
        queue<int> q;
        q.push(0);
        vector<int>visited(totalCapacity+1,false);
        visited[0] = true;
        
        while(q.empty()==false)
        {
            int possibleCapacity = q.front();
            q.pop();
            if(possibleCapacity==targetCapacity)
                return true;
            
            
            for(int i :steps)
            {
                if(possibleCapacity+i>=0 and possibleCapacity+i<=totalCapacity and visited[possibleCapacity+i]==false)
                {
                    visited[possibleCapacity+i]=true;
                    q.push(possibleCapacity+i);
                }
            }
            
        }
        return false;
    }
};


/*
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
*/
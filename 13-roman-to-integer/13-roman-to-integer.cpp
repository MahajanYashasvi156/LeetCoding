class Solution {
public:
    int romanToInt(string A) 
    {
        int result = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] == 'M')
            {
                result+=1000;
            }
            else if(A[i] == 'C' and A[i+1]=='M')
            {
                result+=900;
                i++;
            }
            else if(A[i] == 'D')
            {
                result+=500;
            }
            else if(A[i] == 'C' and A[i+1]=='D')
            {
                result+=400;
                i++;
            }
            else if(A[i] == 'C')
            {
                result+=100;
            }
            else if(A[i] == 'X' and A[i+1]=='C')
            {
                result+=90;
                i++;
            }
            else if(A[i] == 'L' )
            {
                result+=50;
            }
            else if(A[i] == 'X' and A[i+1]=='L')
            {
                result+=40;
                i++;
            }
            else if(A[i] == 'X')
            {
                result+=10;
            }
            else if(A[i] == 'I' and A[i+1]=='X')
            {
                result+=9;
                i++;
            }
            else if(A[i] == 'V')
            {
                result+=5;
            }
            else if(A[i] == 'I' and A[i+1]=='V')
            {
                result+=4;
                i++;
            }
            else if(A[i] == 'I')
            {
                result+=1;
            }
        }
        return result;
        
    }
};
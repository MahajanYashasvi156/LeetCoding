class Solution 
{
public:
    string convert(string A, int B) 
    {
        if(B==1)
        return A;
        string result ="";
        int i = 0;
        int even = 2*(B-2)+2;
        int odd = 0;
        while(i<B)
        {
            int c = 0;
            int j = i;
            while(j<A.size())
            {
                result = result+A[j];
                if(i == 0)
                    j += even;
                else if(i==B-1)
                     j+=odd;
                else if(c++%2==0)
                    j += even;
                else
                    j+=odd;
            }
            even = even -2;
            odd= odd+2;
            i++;
        }
        return result;
    }
};
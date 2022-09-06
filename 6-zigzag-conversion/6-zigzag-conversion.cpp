/*
    p(0)     6          i(6)         6      n(12)
    a(1)     4  l(5)  2 s(7)   4    i(11) 2  g(13)
    y(2) 2  a(4) 4      h(8)   2 r(10)
    p(3)     6          i(9)


*/
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
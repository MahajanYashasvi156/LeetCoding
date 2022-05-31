class Solution {
public:
    int strStr(string A, string B) {
        int index = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(B[index]==A[i])
            {
                index++;
                if(index == B.size())
                {
                    return i - B.size()+1;
                }
            }
            else
            {
                //A = ababca and B = abc then have to go back again to search.  
                i= i - index;
                index = 0;

            }
        }
        return -1;
    }
};
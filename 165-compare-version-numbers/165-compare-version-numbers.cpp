class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        int i1=0;
        int i2=0;
        unsigned int rev1 = 0;
        unsigned int rev2 = 0;
        while(i1<version1.size() or i2<version2.size())
        {
            while( i1<version1.size() and version1[i1] != '.' )
            {
                rev1 = rev1*10 + version1[i1++]-'0';
            } 
           while( i2<version2.size() and version2[i2] != '.' )
            {
                rev2 = rev2*10 + version2[i2++]-'0';
            } 
            if(rev1>rev2)
                    return 1;
            else if(rev1<rev2)
                    return -1;
            else
            {
                rev1 = 0;
                rev2 = 0;
                i1++;
                i2++;
            }
        }
            return 0;
    }
};
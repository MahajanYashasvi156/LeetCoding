class Solution 
{
    unordered_map<string,bool> m;
    
public:
    bool isScramble(string s1, string s2) 
    {
        if(s1==s2)
            return true;
        
        if(m.find(s1+"*"+s2)!=m.end())
            return m[s1+"*"+s2];
    
        int n = s1.size();
        for(int i = 1;i<n;i++)
        {
            int flip = isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i),s2.substr(i));
            
            int noflip = isScramble(s1.substr(0,i),s2.substr(n-i)) and isScramble(s1.substr(i),s2.substr(0,n-i));
            
            if(flip or noflip)
            {
                return m[s1+"*"+s2]=true;
            }   
        }
        return m[s1+"*"+s2]=false;
    }
};




/*
class Solution 
{
    unordered_map<string,bool> m;
public:
    bool isScramble(string A, string B) 
    {
        int n = A.size();
    
        if(A==B)
            return 1;
        if(m.find(A+"*"+B)!=m.end())
            return m[A+"*"+B];
        for(int i = 1;i<n;i++)
        {
            int noFlip = isScramble(A.substr(0,i),B.substr(0,i)) and isScramble(A.substr(i),B.substr(i));
            int flip = isScramble(A.substr(0,i),B.substr(n-i)) and isScramble(A.substr(i),B.substr(0,n-i));

            if(noFlip or flip)
                return  m[A+"*"+B]  = true;
        }
        return  m[A+"*"+B]  = false;
    }
};
*/
/*
class Solution 
{
    unordered_map<string,bool> m;
public:
    bool isScramble(string A, string B) 
    {
        int n = A.size();

        if(A==B)
            return 1;

        if(m.find(A+"*"+B)!=m.end())
            return m[A+"*"+B];

        //Prune if frequency of characters not matched.
        vector<int> f1(26),f2(26);
        for(char c:A)
            f1[c-'a']++;
        for(char c:A)
            f2[c-'a']++;
        if(f1!=f2)
             return  m[A+"*"+B]  = false;

        for(int i = 1;i<n;i++)
        {
            int noFlip = isScramble(A.substr(0,i),B.substr(0,i)) and isScramble(A.substr(i),B.substr(i));
            int flip = isScramble(A.substr(0,i),B.substr(n-i)) and isScramble(A.substr(i),B.substr(0,n-i));

            if(noFlip or flip)
                return  m[A+"*"+B]  = true;
        }
        return  m[A+"*"+B]  = false;
    }
};
*/
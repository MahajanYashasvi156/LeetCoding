class Solution 
{
public:
    string gcdOfStrings(string str1, string str2) 
    {
        string s;
        string ans;
        for(int i = 0;i<min(str1.size(),str2.size()); i++)
        {
            s = s + str1[i];
            
            int n1 = str1.size()/s.size();
            int n2 = str2.size()/s.size();
            
            string temp1;
            string temp2;
            
            for(int i = 0;i<n1;i++)
            {
                temp1 = temp1 + s;
            }
            
            for(int i = 0;i<n2;i++)
            {
                temp2 = temp2 + s;
            }
            
            if(str1==temp1 and str2==temp2)
            {
                ans = s;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string convertToTitle(int A) 
    {
        string title = "";
        while(A)
        {
            int remainder = A%26;
            A= A/26;
            if(remainder == 0)
            {
                remainder = 26;
                A=A-1;
            }
            title = title + char(remainder+64);
        }
        reverse(title.begin(),title.end());
        return title;
    }
};
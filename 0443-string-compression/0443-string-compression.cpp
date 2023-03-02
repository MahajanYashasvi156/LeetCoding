class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        char c = '#' ;
        int count = 0;
        for(int i = 0;i<chars.size();i++)
        {
            if(c==chars[i])
            {
                count++;
            }
            else 
            {
                if(count==1)
                    s = s + c;
                else if(count>0)
                    s = s + c+to_string(count);
                c = chars[i];
                count = 1;
            }
        }
        if(count==1)
                s = s + c;
        else if(count>0)
            s = s + c+to_string(count);
        
        for(int i = 0;i<s.size();i++)
        {
            chars[i] = s[i];
        }
        return s.size();
    }
};
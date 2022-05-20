class Solution {
   static bool compare(string i1, string i2)
    {
        return (i1+i2>i2+i1);
    }
public:
    //comparator - descending order
    string largestNumber(vector<int>& A)
    {
        vector<string> s;
        for(auto a : A)
            s.push_back(to_string(a));
        sort(s.begin(),s.end(),compare);
        string result = "";
        for(int i =0;i<s.size();i++)
        {
            result +=s[i];
        }
        if(result[0]=='0') 
        return "0";
        return result;
    }
};
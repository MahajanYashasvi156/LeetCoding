class Solution {
    static bool cmp(int a, int b)
    {
        string num1 = to_string(a) + to_string(b);
        string num2 = to_string(b) + to_string(a);
        return stol(num1) > stol(num2);
    }
public:
    //comparator - descending order
    string largestNumber(vector<int>& v)
    {
        sort(v.begin(), v.end(),cmp);
        string result="";
        if(v[0]==0)
            return "0";
        for(int i=0;i<v.size();i++)
        {
            result+=to_string(v[i]);
        }
        return result;
    }
};
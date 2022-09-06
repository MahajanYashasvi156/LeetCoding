class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num1=="0" or num2=="0")
            return "0";
        vector<int>num(num1.size()+num2.size(),0);
        
        for(int i = num1.size()-1;i>=0;i--)
        {
            for(int j = num2.size()-1;j>=0;j--)
            {
                num[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                num[i+j] += num[i+j+1]/10;
                num[i+j+1] = num[i+j+1]%10;
            }
        }
        
        int start = 0;
        while(num[start]==0)start++;
        
        string product = "";
        
        while(start<num1.size()+num2.size())
        {
            product.append(to_string(num[start++]));
        }
        return product;
    }
};
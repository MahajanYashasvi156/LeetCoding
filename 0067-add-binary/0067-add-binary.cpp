class Solution {
public:
    string addBinary(string A, string B) 
    {
        /*
        string res="";
        int i=M.size()-1,j=N.size()-1,c=0;
       
        while(i>=0 || j>=0 || c==1){
            int x = (i>=0)?(M[i--]-'0'):0;
            int y = (j>=0)?(N[j--]-'0'):0;
            int sum = x+y+c;
            res+=(sum%2)+'0';
            c=sum/2;
        }
    
        reverse(res.begin(),res.end());
        return res;
        */
       string result="";
        int i = A.size()-1;
        int j = B.size()-1;
        int Cin = 0;
        while(i>=0 or j >=0 or Cin) 
        {
            int a = i>=0?A[i]-'0':0;
            int b = j>=0?B[j]-'0':0;
            result = result + to_string(a^b^Cin);
            Cin = (a & b) | ((a^b) & Cin) ;
            i--;
            j--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
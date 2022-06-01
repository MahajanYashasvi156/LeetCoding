class Solution {
public:
    string addBinary(string M, string N) 
    {
        string result="";
        vector<int>A;
        vector<int>B;
        for(auto a :M)
            A.push_back(a-'0');
        for(auto a :N)
            B.push_back(a-'0');

        int i = A.size()-1;
        int j = B.size()-1;
        int Cin = 0;
        while(i>=0 and j >=0)
        {
            result = result + to_string(A[i]^B[j]^Cin);
            Cin = (A[i] & B[j]) | ((A[i]^B[j]) & Cin) ;
            i--;
            j--;
        }
        while(i>=0)
        {
            result = result + to_string(A[i]^Cin);
            Cin = A[i] & Cin ;
            i--;

        }
        while(j>=0)
        {
            result = result + to_string(B[j]^Cin);
            Cin = B[j] & Cin;
            j--;
        }
        if(Cin)
            result+="1";
        reverse(result.begin(),result.end());
        return result;
        
    }
};
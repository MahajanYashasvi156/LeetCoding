class Solution {
public:
    vector<int> plusOne(vector<int>& A) 
    {
    vector<int> B(A.begin(),A.end());
    int carry = 1;
    for(int i = B.size()-1 ;i>=0;i--)
    {
        int temp = B[i];
        B[i] = (B[i]+carry)%10;
        carry = (temp+carry)/10;
        if(carry == 0)
            return B;
    }
    B.insert(B.begin(),carry);
    return B;
    }
};
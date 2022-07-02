class Solution 
{
public:
    int maxProduct(vector<int>& A)
    {

        int maxProd = INT_MIN;
        int prod =1;
        for(int i = 0;i<A.size();i++)
        {
            if(prod!=0)
                prod = prod*A[i];
            else
                prod = A[i];

            maxProd = max(maxProd , prod);
        }
        prod = 1;
        for(int i = A.size()-1;i>=0;i--)
        {
            if(prod!=0)
                prod = prod*A[i];
            else
                prod = A[i];

            maxProd = max(maxProd , prod);
        }
        return maxProd;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& A) 
    {
        vector<int>count(A.size(),0);
        for(int i =0;i<A.size();i++)
        {
            count[A[i]]++;
            if(count[A[i]]>1)
                return A[i];
        }
        return -1;
    }
};
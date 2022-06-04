class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) 
    {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<int> result;
        int i = 0;
        int j = 0;
        while(i<A.size() and j<B.size())
        {
            if(A[i]==B[j])
            {
                //Because duplicates not allowed
                if(result.size()==0 or result[result.size()-1]<A[i])
                    result.push_back(A[i]);
                i++;
                j++;
            }
            else if(A[i]<B[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return result;
    }
};
class Solution 
{
    void generatePermutation(vector<int>&A,int index,vector<vector<int>>&allPermutation,set<vector<int>>&s)
    {
        if(index==A.size())
        {
            s.insert(A);
            return;
        }
        for(int i = index;i<A.size();i++)
        {
            swap(A[i],A[index]);
            generatePermutation(A,index+1,allPermutation,s);
            swap(A[i],A[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& A) 
    {
        set<vector<int>>s;
        vector<vector<int>> allPermutation;
        generatePermutation(A,0,allPermutation,s);
        for(auto a:s)
            allPermutation.push_back(a);
        return allPermutation;
        
    }
};
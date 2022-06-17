class Solution 
{
public:
    vector<int> twoSum(vector<int>& A, int target) 
    {
        unordered_map<int,int> m;
 
        for(int i = 0;i<A.size();i++)
        {
            if(m.find(target-A[i])!=m.end())
                return {m[target-A[i]],i};
            m[A[i]]=i;
        }
        return {};
    }
};


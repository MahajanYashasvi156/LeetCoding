class Solution 
{
public:
    int subarraysWithKDistinct(vector<int>& A, int B) 
    {
        unordered_map<int,int> m; 
        int low = 0;
        int high = 0;
        int atmostB = 0;
        while(high<A.size())
        {
            int count = m.size();
            if(m.find(A[high])==m.end())
                count++;
            if(count<=B)
            {
                atmostB = atmostB+high-low+1;
                m[A[high]]++;
                high++;
            }
            else 
            {
                m[A[low]]--;
                if(m[A[low]]==0)
                {
                    m.erase(A[low]);
                }
                low++;
            }
        }
        if(B==1)
            return atmostB;
        m.clear();
        low = 0;
        high = 0;
        int atmostB1 = 0;
        while(high<A.size())
        {
             int count = m.size();
            if(m.find(A[high])==m.end())
                count++;
            if(count<=B-1)
            {
                atmostB1 = atmostB1+high-low+1;
                m[A[high]]++;
                high++;
            }
            else 
            {
                m[A[low]]--;
                if(m[A[low]]==0)
                {
                    m.erase(A[low]);
                }
                low++;
            }
        }
        return atmostB-atmostB1;
    }
};
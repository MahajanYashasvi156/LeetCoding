class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int>res;
        
        int symmetric = n/2;
        
        for(int i = (-1)*symmetric ;i<=symmetric;i++)
        {
            if(n%2==0 and i==0)
                continue;
            res.push_back(i);
        }
        return res;
    }
};
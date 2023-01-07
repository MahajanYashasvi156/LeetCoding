class Solution 
{
public:
    int canCompleteCircuit(vector<int>& A, vector<int>& B) 
    {
        int gas = accumulate(A.begin(),A.end(),0);
        int cost = accumulate(B.begin(),B.end(),0);

        if(cost>gas)
            return -1;
        int ans = 0;
        gas = 0;
        cost = 0;
        for(int i = 0;i<A.size();i++)
        {
            gas = gas+A[i];
            cost = cost +B[i];
            if(gas-cost<0)
            {
                ans = i+1;
                gas = 0;
                cost = 0;
            }
        }
        return ans;
    }
};
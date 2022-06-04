class Solution 
{
public:
    int threeSumClosest(vector<int>& A, int B) 
    {
        sort(A.begin(),A.end());
        int closestSum = INT_MAX;
        int diff = INT_MAX;
        
        for(int i = 0;i<A.size()-2;i++)
        { 
            int low = i+1;
            int high = A.size()-1;

            while(low<high)
            {
                int num = A[i]+A[low]+A[high];
                if(abs(B-num)==0)
                    return num;
                if(diff>abs(B-num))
                {
                    diff = abs(B-num);
                    closestSum = num;
                }
                if(num>B)
                    high--;
                else
                    low++;
            }
        }
        return closestSum;
        
    }
};
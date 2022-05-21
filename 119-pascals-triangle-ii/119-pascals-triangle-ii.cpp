class Solution {
public:
    vector<int> getRow(int A) 
    {
            vector<int> result;
            result.push_back(1);
            for(int i=1;i<=A;i++)
            {
                result.push_back(0);
                for(int j=result.size()-1;j>0;j--)
                {
                    result[j] = result[j]+result[j-1];
                }
            }
            return result;
    }
};
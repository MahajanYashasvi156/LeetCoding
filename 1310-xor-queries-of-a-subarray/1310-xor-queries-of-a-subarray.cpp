class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int> prefixXor(arr.size(),0);
        
        prefixXor[0] = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            prefixXor[i] = prefixXor[i-1]^arr[i];
        }
        
        vector<int>result(queries.size());
        for(int i = 0;i<queries.size();i++)
        {
            int low = queries[i][0];
            int high = queries[i][1];
            
            if(low>0)
                result[i]= prefixXor[high]^prefixXor[low-1];
            else
                result[i]= prefixXor[high];
        }
        return result;
    }
};
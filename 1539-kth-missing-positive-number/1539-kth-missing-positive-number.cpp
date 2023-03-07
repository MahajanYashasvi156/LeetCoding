class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int i = 0;
        vector<int> missing;
        int count = 1;
        while(missing.size()<k and i<arr.size())
        {
            for(int j = count;j<arr[i];j++)
            {
                missing.push_back(j);
            }
            
            count = arr[i]+1;
            i++;
        }
        
        if(i==arr.size())
        {
            int s = missing.size();
            for(int j = s;j<k;j++)
            {
                missing.push_back(count++);
            }
        }
         return missing[k-1];
    }
   
};
//https://leetcode.com/problems/maximum-of-absolute-value-expression/discuss/339968/JavaC%2B%2BPython-Maximum-Manhattan-Distance

class Solution {
public:
   int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        int res = 0, n = x.size(), smallest, cur;
        for (int p : {1, -1}) {
            for (int q : {1, -1}) {
                smallest = p * x[0] + q * y[0] + 0;
                for (int i = 1; i < n; ++i) {
                    cur = p * x[i] + q * y[i] + i;
                    res = max(res, cur - smallest);
                    smallest = min(smallest, cur);
                }
            }
        }
        return res;
    }
};

/*class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) 
    {
        int min1 = INT_MAX;
        int max1 = INT_MIN;
        int min2 = INT_MAX;
        int max2 = INT_MIN;
        int min3 = INT_MAX;
        int max3 = INT_MIN;
        int min4 = INT_MAX;
        int max4 = INT_MIN;
        
        for(int i = 0;i<arr1.size();i++)
        {
            min1 = min(min1,arr1[i]+arr2[i]+i);
            max1 = max(max1,arr1[i]+arr2[i]+i);
            
            min2 = min(min2,arr1[i]+arr2[i]-i);
            max2 = max(max2,arr1[i]+arr2[i]-i);
            
            min3 = min(min3,arr1[i]-arr2[i]+i);
            max3 = max(max3,arr1[i]-arr2[i]+i);
            
            min4 = min(min4,arr1[i]-arr2[i]-i);
            max4 = max(max4,arr1[i]-arr2[i]-i);
            
        }
        
        return max(max1-min1,max(max2-min2,max(max3-min3,max4-min4)));
    }
};
*/

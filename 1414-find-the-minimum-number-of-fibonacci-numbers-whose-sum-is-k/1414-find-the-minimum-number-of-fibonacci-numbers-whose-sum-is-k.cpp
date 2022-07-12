class Solution {
public:
    int findMinFibonacciNumbers(int k) 
    {
        vector<int> fib;
        
        int first = 1;
        int second = 1;
        
        fib.push_back(first);
        fib.push_back(second);
        
        while(second<=k)
        {
            int curr = first+second;
            fib.push_back(curr);
            second = first;
            first = curr;
             
        }
        
        int count = 0;
        while(k>0)
        {
            k = k - *(--upper_bound(fib.begin(),fib.end(),k));
            count++;
        }
        return count;
    }
};
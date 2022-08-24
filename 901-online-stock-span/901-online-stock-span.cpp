class StockSpanner 
{
    stack<pair<int,int>> monotonicallyIncreasingStocks;
    int index = 0;
    
public:
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
        while(!monotonicallyIncreasingStocks.empty() and monotonicallyIncreasingStocks.top().second<=price)
         monotonicallyIncreasingStocks.pop();
        
        index++;
        int ans = index;
        
        if(!monotonicallyIncreasingStocks.empty())
            ans = ans - monotonicallyIncreasingStocks.top().first;
       
        monotonicallyIncreasingStocks.push({index,price});
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
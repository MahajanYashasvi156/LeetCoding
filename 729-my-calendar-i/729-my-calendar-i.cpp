class MyCalendar 
{
    set<pair<int,int>>booking;
public:
    MyCalendar() 
    {
            
    }
    
    bool book(int start, int end) 
    {
        int low = 0;
        int high = booking.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            auto it = booking.begin();
            std::advance(it,mid);
        
            int prevend = it->first;
            int prevstart = it->second;
            
            if(prevstart<=start and start<prevend or prevstart<end and end<prevend or start<prevstart and end>=prevend)
                return false;
            
            if(start>=prevend)
                low = mid+1;
            else
                high = mid-1;
            
        }   
        booking.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
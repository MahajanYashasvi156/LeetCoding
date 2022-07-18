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
        
            if(it->second<=start and start<it->first or it->second<end and end<it->first or start<=it->second and end>=it->first)
                return false;
            
            if(start>=it->first)
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
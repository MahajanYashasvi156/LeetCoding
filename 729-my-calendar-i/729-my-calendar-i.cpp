class MyCalendar 
{
    vector<pair<int,int>>booking;
public:
    MyCalendar() 
    {
            
    }
    
    bool book(int start, int end) 
    {
        for(auto b:booking)
        {
            int prevStart = b.first;
            int prevEnd =  b.second;
            if(prevStart<end and start<prevEnd)
                return false;
        }       
        booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
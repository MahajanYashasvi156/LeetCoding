class Solution 
{
    static bool comp(vector<int>&c1 ,vector<int>&c2)
    {
        return c1[1]<c2[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int> maxheap;
        int days = 0;
        for(int i = 0;i<courses.size();i++)
        {
            int duration = courses[i][0];
            int lastday = courses[i][1];
            
            if(days+duration<=lastday)
            {
                days = days+duration;
                maxheap.push(duration);
            }
            else 
            {
                if(maxheap.size() and maxheap.top()>duration)
                {
                    days = days-maxheap.top() + duration;
                    maxheap.pop();
                    maxheap.push(duration);
                }
            }
        }
        return maxheap.size();
    }
};
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        unordered_map<int,long long> m;

        for(int i = 0;i<tasks.size();i++)
        {
            if(m.find(tasks[i])!=m.end())
            {
                if(day-m[tasks[i]]<space)
                {
                    day = day + space-(day-m[tasks[i]]);
                }
            }
            day++;
            m[tasks[i]] = day;
           
        }
        return day;
    }
};
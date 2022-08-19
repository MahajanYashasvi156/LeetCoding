class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int,vector<int>> index;
        
        vector<int> count(nums.size(),INT_MAX);
        
        for(int i = 0;i<nums.size();i++)
        {
            if(index.find(nums[i]-1)!=index.end())
            {
                int mini = INT_MAX;
                int previndex = -1;
                int c = 0;
                int m = -1;
                for(int j:index[nums[i]-1])
                {
                    if(mini>count[j])
                    {
                        mini = count[j];
                        previndex = j;
                        m = c;
                    }
                    c++;
                }
                //cout<<i<<": "<<previndex<<" ,";
                index[nums[i]-1].erase(index[nums[i]-1].begin()+m);
                if(index[nums[i]-1].size()==0)
                {
                    index.erase(nums[i]-1);
                    //cout<<"done"<<endl;
                }
               
                    
                count[i] = count[previndex]+1;
                count[previndex] = -1;
                
            }
            else
            {
                count[i] = 1;
            }
            index[nums[i]].push_back(i);
        }
        for(int c : count)
        {
            //cout<<c<<endl;
            if(c<3 and c!=-1)
                return false;
        }
        return true;
    }
};
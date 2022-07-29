class Solution 
{
//     1 2 3 4 7
//         1 2 3 5 7
//         1 2 4 5 7
        
        
//     [1,2,4,3,5,4,7,2]
// len - 1 
        
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        vector<int> length(nums.size(),0);
        vector<int> count(nums.size(),0);
        
        length[0] = 1;
        count[0] = 1;
        
        for(int i = 1;i<nums.size();i++)
        {
            int c = 1;
            int maxi = 0;
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(maxi<length[j])
                    {
                        maxi = length[j];
                        c = count[j];
                    }
                    else if(maxi==length[j])
                    {
                        c = c+count[j];
                    }
                }
                
            }
            length[i] = maxi+1;
            count[i] = c;
        }
        int maxLength = *max_element(length.begin(),length.end());
        
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            cout<<length[i]<<" "<<count[i]<<endl;
            if(length[i]==maxLength)
            {
                ans+=count[i];
            }
        }
        return ans;
    }
};
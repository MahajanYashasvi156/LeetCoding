class Solution 
{    
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        //length[i] : maximum length of the LIS ending at ith index.
        //count[i] : no of ways of getting maximal LIS ending at ith index.
        vector<int> length(nums.size(),0);
        vector<int> count(nums.size(),0);
        
        for(int i = 0;i<nums.size();i++)
        {
            //If there would no elemnt which is smaller than current elememt then also it will make length 1 LIS by not taking any previous elemnt that's the one way.
            //c : no of ways of picking LIS from the previous elemnts.
            //maxi : length of the LIS from the previous elemnts.
            int c = 1; 
            int maxi = 0;
            for(int j = 0;j<i;j++)
            {
                //if the previous element is smaller than current elemnt then only it can be the part of LIS ending at current element.
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
            if(length[i]==maxLength)
                ans+=count[i];
        }
        return ans;
    }
};

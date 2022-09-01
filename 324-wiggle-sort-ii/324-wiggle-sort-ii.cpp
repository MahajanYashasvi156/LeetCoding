class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int i = 1;
        int j = nums.size()-1;
        vector<int> res(nums.size());
        while(i<nums.size())
        {
            res[i] = nums[j];
            j--;
            i=i+2;
            
        }
        i = 0;
        while(i<nums.size())
        {
            res[i] = nums[j];
            j--;
            i=i+2;
        }
        
        for(int i = 0;i<nums.size();i++)
            nums[i]=res[i];
    }
};


/*
Wiggle sort 1 

class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(i%2==0) //even
            {
                if(nums[i]>nums[i+1])
                    swap(nums[i],nums[i+1]);
            }
            else
            {
                if(nums[i+1]>nums[i])
                    swap(nums[i],nums[i+1]);
                    
            }
        }
    }
};

*/

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int low = -10001;
        int high = 10001;
        int ans = INT_MIN;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int greaterElements = 0;
            for(int a:nums)
            {
                if(a>=mid)
                {
                    greaterElements++;
                }
            }
            if(greaterElements<k)
            {
                high = mid-1;
            }
            else
            {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    int partition(vector<int> & nums,int low,int high)
    {
        int i=low-1;
        int j=low;
        int pivot=nums[high];
        while(j<high)
        {
            if(nums[j]>=pivot)
            {
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        i++;
        swap(nums[i],nums[high]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        int low=0;
        int high=nums.size()-1;
        int pivotindex;
        while(low<=high)
        {
            pivotindex=partition(nums,low,high);
            if((pivotindex+1)==k)
                return nums[pivotindex];
            else if ((pivotindex+1)>k)
                high=pivotindex-1;
            else
                low=pivotindex+1;
        }
        return -1;
    }
};
*/
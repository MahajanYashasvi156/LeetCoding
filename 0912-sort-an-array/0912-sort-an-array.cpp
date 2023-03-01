class Solution 
{
public:
    void merge(vector<int>&nums,int low,int mid,int high)
    {
        vector<int> temp(high-low+1);
        
        int l=low;
        int r = mid+1;
        int k = 0;
        while(l<=mid and r<=high)
        {
            if(nums[l]<=nums[r])
            {
                temp[k++] = nums[l++];
            }
            else
            {
                temp[k++] = nums[r++];
            }
        }
        
        while(l<=mid)
        {
            temp[k++] = nums[l++];
        }
        
        while(r<=high)
        {
            temp[k++] = nums[r++];
        }
        
        for(int i = 0;i<k;i++)
        {
            nums[low+i] = temp[i];
        }
    }
    void mergeSort(vector<int>&nums,int low,int high)
    {
        if(low<high)
        {
            int mid = (low+high)/2;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
    
    
};
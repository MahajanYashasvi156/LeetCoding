class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        //If window size is 1 then single element is always maximum.
        if(k==1)
            return nums;
        
        int max_elem=INT_MIN;
        vector<int> result;
        //Frequency map to store the window elements as key and their frequency as value.
        map<int,int> count;
        
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
            //Process the current window when the index i is at the end of the window.
            if(i>=k-1)
            {
                 max_elem=count.rbegin()->first;
                //Push the current max_elem as the max element of the processing window.
                result.push_back(max_elem);
                //Reduce freqency of the 1st element of the window as it is going to be out of the window for next windows.
                count[nums[i-k+1]]--;
                //If the 1st element of the window has no other duplicate present within the window then erase it from the map.
                if(count[nums[i-k+1]]==0)
                    count.erase(nums[i-k+1]);
            }
        }
        return result;
    }
};
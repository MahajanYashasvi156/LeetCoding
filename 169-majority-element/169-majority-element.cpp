/*
The task is to find the element that appears more than n/2 times. So, it appears more than all other numbers combined.
So, we starting from LSB (least significant bit) of every number of the array, 
we count in how many numbers of the array it is set. If any bit is set in more than n/2 numbers, then that bit is set in our majority element.
This approach works because for all other numbers combined the set bit count can’t be more than n/2,
as the majority element is present more than n/2 times.


If we are not sure that majority elemnt always present then the result is candidate to be majority elemnt so confirm it one's by traversing complete array.
If majority elemnt is for sure present then no need of confirming, candidate will be the majority elemnt.
Bit Magic.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int ans=0;
        int length= 32;
        int count=0;
        for(int i=0;i<length;i++)
        {
            count=0;
            for(int j=0;j<nums.size();j++)
                if(nums[j] & (1<<i))
                    count++;
            if(count>nums.size()/2)
                ans = ans+(1<<i);
        }
        return ans;
        
    /*
                Moore's Voting Algorithm.
    1.consider 1st element to be candidate to become majority element.
    2.Iterate over all elements and if the element is candidate then inc count.
    3. If the element is not candidate the decrement count.
         a) If count = 0 then update the candidate with the current element.
     
        int candidate=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==candidate)
                count++;
            else
            {
                count--;
                if(count==0)
                {
                    candidate=nums[i];
                    count=1;
                }
            }
        }
        return candidate;
        */ 
    }
};
/*
Link - https://leetcode.com/problems/rotate-array/
TC - O(N)
SC - O(N)
*/
/*
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>temp = nums;
        
       for(int i=0;i<n;i++)
             nums[(i+k)%n]=temp[i];
    }
};
*/

/*
TC - O(N)
SC - O(1)
*/

class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k%n;
        //Reverse all
        reverse(nums.begin(),nums.end());
        //Reverse first k
        reverse(nums.begin(),nums.begin()+k);
        //Reverse remaining
        reverse(nums.begin()+k,nums.end());
    }
};


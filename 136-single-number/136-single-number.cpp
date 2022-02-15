class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for(int n :nums)
            result = result ^ n;
        return result;
    }
};
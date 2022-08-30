//Considering the end of the arithmetic sequence at the current position
class Solution 
{
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        unordered_map<int,int> m;

        int ans = INT_MIN;
        
        for(int i = 0;i<arr.size();i++)
        {
            int lengthTillNow = 0;
            
            if(m.find(arr[i]-difference)!=m.end())
                lengthTillNow= m[arr[i]-difference]+1;

            else
                lengthTillNow = 1;
            
            m[arr[i]]=lengthTillNow;
            
            ans = max(ans,lengthTillNow);
        }
        
        return ans;
    }
};
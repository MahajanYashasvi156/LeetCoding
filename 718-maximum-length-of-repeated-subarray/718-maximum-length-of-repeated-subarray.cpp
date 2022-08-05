class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int ans = 0;
        
        for(int i = 1;i<=nums1.size();i++)
        {
            for(int j = 1;j<=nums2.size();j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
    
};



/*
class Solution 
{
    bool search(vector<int>& nums1,vector<int>& nums2, int len)
    {
        unordered_map<long long,vector<int>> hashMatch;  
        vector<long long> hashMultiplier(len);
        hashMultiplier[len-1] = 1;
        for(int i = len-2;i>=0;i--)
        {
            hashMultiplier[i] = (hashMultiplier[i+1]*10)%1000000007;
        }
        long long hashValue = 0;
        
        for(int i = 0;i<nums2.size()-len;i++)
        {
            hashValue = ((hashValue*10)%1000000007 + nums2[i])%1000000007;
            if(i>=len-1)
            {
                hashMatch[hashValue].push_back(i-len-1);
            }
        }
        
        for( int i = 0;i<len;i++)
        {
            cout<<i<<endl;
            if(i<=len-1)
            {
                cout<<"1"<<endl;
                 hashValue = ((hashValue*10)%1000000007 + nums1[i])%1000000007;
            }
            else
            {
                cout<<"2"<<endl;
                cout<<nums1[i-len-1]<<" "<<hashMultiplier[0]<<endl;
                cout<<"3"<<endl;
                hashValue = ((hashValue - (nums1[i-len]*hashMultiplier[0])%1000000007)%1000000007 + 1000000007)%1000000007;
                hashValue = ((hashValue*10)%1000000007+nums1[i])%1000000007;
        
            }
            
            if(i>=len-1)
            {
                if(hashMatch.find(hashValue)!=hashMatch.end())
                {  
                    for(int start : hashMatch[hashValue])
                    {
                        bool flag = true;
                        for(int j = start,k = i-len+1;j<start+len;j++,k++)
                        {
                            if(nums2[j]!=nums1[k])
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag)
                        {
                            return true;
                        }
                    }
                }
            }
            
        }
        return false;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int high = min(nums1.size(),nums2.size());
        int low = 0;
        
        int ans = 0;
        
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            
            if(search(nums1,nums2,mid))
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};
*/
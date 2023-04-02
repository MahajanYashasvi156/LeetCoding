class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        
        vector<int> ans(spells.size());
        for(int i = 0;i<spells.size();i++)
        {
            
            int low = 0;
            int high = potions.size()-1;
            
            while(low<=high)
            {
                int mid = (low+high)/2;
               
                if((long long)spells[i]*potions[mid]>=success)
                {
                    ans[i] = potions.size()-mid;
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            //cout<<ans[i]<<endl;
        }
        return ans;
    }
};
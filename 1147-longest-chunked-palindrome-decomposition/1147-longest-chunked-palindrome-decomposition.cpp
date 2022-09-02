class Solution {
public:
    int longestDecomposition(string text) 
    {
        string s ="";
        int ans = 0;
        int n = text.size();
        int low = 0;
        int high = n-1;
        
        while(low<=high)
        {
            while(low<text.size() and text[low]!=text[high])
            {
                s = s+text[low];
                low++;
            }
            s = s+text[low];
    
            if(s == text.substr(high-s.size()+1,s.size()))
            {
                //if the string is at the middle position
                if(low==high)
                    ans = ans+1;
                else
                    ans = ans + 2;
                
                high = high-s.size();
                s = "";
            }
            low++;
        }
        return ans;
    }
};
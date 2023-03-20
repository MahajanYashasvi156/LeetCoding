class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        int i = 0;
        
        for(int j = 0;j<flowerbed.size();j++)
        {
            if(flowerbed[j]==1)
            {
                if(j>1)
                {
                    count = count + ceil((j-i-1)/2.0);
                    
                }
                i = j+2;
            }
            else if(j == flowerbed.size()-1)
            {
                 count = count + ceil((j-i+1)/2.0);
            }
        }
     
        return count>=n;
    }
};
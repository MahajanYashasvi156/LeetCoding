class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<unordered_map<char,int>>freq(words1.size());
        
        for(int i = 0;i<words1.size();i++)
        {
            for(char c: words1[i])
            {
                freq[i][c]++;
            }
        }
        //Store the maximum frequency of each character in each word of B. So that we just need to find whether a word in words1 has that much frequency in it. If no then that cant be universal list.
        unordered_map<char,int> word2Freq;
        for(int i = 0;i<words2.size();i++)
        {
            unordered_map<char,int> temp;
            for(char c: words2[i])
            {
                temp[c]++;
                if(word2Freq[c]<temp[c])
                    word2Freq[c] = temp[c];
            }
        }
        vector<string> result;
        
        for(int i = 0;i<words1.size();i++)
        {
            int flag = 0;
            for(auto a : word2Freq)
            {
                char c = a.first;
                int val = a.second;
                if(freq[i][c]<val)
                {
                    flag = 1;
                    break;
                }   
            }
            if(flag==0)
                result.push_back(words1[i]);
        }
        return result;
        
        
    }
};
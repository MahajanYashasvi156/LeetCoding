class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> result;
        
        int n = pattern.size();
        for(int i = 0;i<words.size();i++)
        {
            unordered_map<char,char> patternmap;
            unordered_map<char,char> wordmap;
            bool flag = false;
            for(int j = 0;j<n;j++)
            {
                if(patternmap.find(pattern[j])==patternmap.end() and wordmap.find(words[i][j])==wordmap.end())
                {
                    patternmap[pattern[j]] = words[i][j];
                    wordmap[words[i][j]] = pattern[j];
                }
                else if(patternmap.find(pattern[j])!=patternmap.end() and patternmap[pattern[j]]==words[i][j])
                {
                     continue;
                }
                   
                else
                {
                    flag = true;
                    break;
                }    
            }
            if(flag == false)
                result.push_back(words[i]);
        }
        return result;
    }
};
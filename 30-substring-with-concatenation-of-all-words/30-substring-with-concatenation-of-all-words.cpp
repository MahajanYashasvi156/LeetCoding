class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int> wordsFreq;
        
        for(string s : words)
            wordsFreq[s]++;
        
        int wordLen = words[0].size();
        int totalSize = wordLen*words.size();
        vector<int> result;
        if(s.size()<totalSize)
            return {};
        //From each index check whether the window strtimg from ith index could be our answer.
        for(int i = 0;i<=s.size()-totalSize;i++)
        {
            bool found = true;
            unordered_map<string,int> window(wordsFreq);
            for(int j = i;j<i+totalSize and j+wordLen<=s.size();j = j +wordLen)
            {
                string currWord = s.substr(j,wordLen);
                if(window.find(currWord)!=window.end() and window[currWord]>0)
                    window[currWord]--;
                else
                {
                    found = false;
                    break;
                }    
            }
            
            if(found == true)
                result.push_back(i);
        }
        
        return result;
    }
};
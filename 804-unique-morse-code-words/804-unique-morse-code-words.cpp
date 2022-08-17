class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        string table[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int>m;
        
        for(string s : words)
        {
            string transformation = "";
            for(char c: s)
                transformation = transformation + table[c-'a'];
            m[transformation]++;
        }
        return m.size();
    }
};
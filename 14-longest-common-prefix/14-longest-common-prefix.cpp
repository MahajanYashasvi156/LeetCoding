/*
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix = "";
        for(int i = 0;i<strs[0].size();i++)
        {
            char c = strs[0][i];
            for(int j = 1;j<strs.size();j++)
            {
                if(i==strs[j].size() || strs[j][i]!=c)
                    return prefix;
            }
            prefix+=c;
        }
        return prefix;
    }
};
*/

class Node
{
    public:
        Node* links[26];
};
class Trie
{
    public:
    Node *node = new Node();
    
    void insert(string s)
    {
        Node *root = node;
        
        for(int i = 0;i<s.size();i++)
        {
            if(root->links[s[i]-'a']==NULL)
                root->links[s[i]-'a'] = new Node();
            root = root->links[s[i]-'a'];
        }
    }
    
    int searchPrefix(string s)
    {
        int size = 0;
         Node *root = node;
        for(int i = 0;i<s.size();i++)
        {
            if(root->links[s[i]-'a']==NULL)
                return size;
            root = root->links[s[i]-'a'];
            size++;
        }
        return size;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) 
    {
        Trie trie;
        trie.insert(s[0]);
        
        int size = s[0].size();
        
        for(int i = 1;i<s.size();i++)
        {
            size = min(size,trie.searchPrefix(s[i]));
        }
        
        return s[0].substr(0,size);
    }
};
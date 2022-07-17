class Node
{
    public:
        Node* links[26];
        bool flag = false;
};
class Trie
{
    Node* node ;
    public:
    Trie()
    {
        node = new Node();
    }
    
    void insert(string s)
    {
        Node* curr = node;
        
        for(int i = 0;i<s.size();i++)
        {
            if(curr->links[s[i]-'a']==NULL)
               curr->links[s[i]-'a'] = new Node();
            curr = curr->links[s[i]-'a'];
        }
        
        curr->flag = true;
    }
    
    bool search(string s)
    {
        Node* curr = node;
        for(int i = 0;i<s.size();i++)
        {
            if(curr->links[s[i]-'a']==NULL)
                return false;
            curr = curr->links[s[i]-'a'];
            if(curr->flag==false)
                return false;
        }
        
        return true;
    }
};

class Solution 
{
public:
    string longestWord(vector<string>& words) 
    {
        Trie trie;
        
        for(string s:words)
            trie.insert(s);
        
        string result = "";
        
        for(string s:words)
        {
            if(s.size()>result.size() and trie.search(s))
            {
                result = s;
            }
            if(s.size()==result.size() and result>s and trie.search(s))
            {
                result = s;
            }
        }
        return result;
    }
};
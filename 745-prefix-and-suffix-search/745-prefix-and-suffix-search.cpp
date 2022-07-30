class Node
{
    public:
    Node* links[27];
    int i = -1;
};
class Trie
{
    public :
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(string s,int index)
    {
        Node* curr = root;
        
        for(int i = 0;i<s.size();i++)
        {
            if(curr->links[s[i]-'a']==NULL)
                curr->links[s[i]-'a'] = new Node();
            curr = curr->links[s[i]-'a'];
            curr->i = max(index,curr->i);
        }
    }
    
    int search(string s)
    {
        Node* curr = root;
        
        for(int i = 0;i<s.size();i++)
        {
            if(curr->links[s[i]-'a']==NULL)
                return -1;
            curr = curr->links[s[i]-'a'];
            
        }
        return curr->i;
    }
};
class WordFilter 
{
public:
    Trie trie;
    WordFilter(vector<string>& words) 
    {
        for(int i = 0;i<words.size();i++)
        {
            string s = "";
            for(int j = words[i].size()-1;j>=0;j--)
            {
                s = words[i][j]+s;
                trie.insert(s+"{"+words[i],i);
            }
        }
    }
    
    int f(string pref, string suff) 
    {
        string temp = suff+"{"+pref;
        return trie.search(temp);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
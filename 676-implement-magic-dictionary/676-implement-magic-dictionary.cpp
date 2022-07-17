class Node
{
    public:
        Node* links[26];
        bool flag = false;
};

class Trie
{
    public:
        Node* node ;
    
        Trie()
        {
            node = new Node();
        }
    
        void insert(string s)
        {
            Node* newNode = node;
            for(int i = 0;i<s.size();i++)
            {
                if(newNode->links[s[i]-'a']==NULL)
                    newNode->links[s[i]-'a'] = new Node();
                newNode = newNode->links[s[i]-'a'];
            }
            newNode->flag = true;
        }
    
        bool search(int i,string s,bool replaced,Node* node)
        {
            if(i==s.size())
            {
                return (node->flag and replaced);
            }
            if(node->links[s[i]-'a']==NULL and replaced)
            {
                return false;
            }
            if(node->links[s[i]-'a'] and search(i+1,s,replaced,node->links[s[i]-'a']))
                    return true;
            
            if(replaced==false)
            {
                for(int j =0;j<26;j++)
                {
                    if(('a'+j)!=s[i] and node->links[j] and search(i+1,s,true,node->links[j]))
                        return true;
                }
            }
            
            return false;
        }
};
class MagicDictionary 
{
   Trie *trie;
public:
    MagicDictionary() 
    {
        trie = new Trie;
    }
    
    void buildDict(vector<string> dictionary) 
    {
        for(string s:dictionary)
        {
            trie->insert(s);
        }
    }
    
    bool search(string searchWord) 
    {
        return trie->search(0,searchWord,false,trie->node);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
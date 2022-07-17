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
            //If at last refrence node and endwith flag is set. Also if we reached at this refrence node changing exactly one character then only we found the word. 
            if(i==s.size())
                return (node->flag and replaced);
            
            //If the current character is not present in the current refrence node and we can't replace any more character then search fails.
            if(node->links[s[i]-'a']==NULL and replaced)
                return false;
    
            /*
            If till now there is no replacement and current char exist in refrence node then we have two option -
            
            1. Either we does not perform replacement and can pick the matched character refrence node .
            2. Else we can replace current character with other refrences character present in the current refrence node.
            */
            
            if(node->links[s[i]-'a'] and search(i+1,s,replaced,node->links[s[i]-'a']))
                    return true;
            
            if(replaced==false)
            {
                for(int j = 'a';j<='z';j++)
                {
                    if(j!=s[i] and node->links[j-'a'] and search(i+1,s,true,node->links[j-'a']))
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